#include <Accelerate/Accelerate.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

    double Mr,Mi,alpha,k,kend,kabs; 
    int i,j,n1,n2,n3,ii,jj;
    FILE *fp;
    char jobz,uplo;
    int lda,lwork,info;
    double *M,*rwork,*work,*w,kx,ky,kz;
    double Rx,Ry,Rz,Mrr,Mii,theta;
    double *MM0,*Tx,*Txd,*Ty,*Tyd,*Tz,*Tzd,*zeeman;
	double *xx,*yy,*zz,dx,dy,dz,dx2,dy2,dz2,dd,dd2;
	int iu,ju,ib,jb; 



	const double aa = 1.0;
	const double AA = 0.5;
	const double BB = 0.25;
	const double BB1 = 0.25;
	const double MM = 0.29;
	const double delta = 0.0;
/*
	const double aa = 4.1355/sqrt(3.0);
	const double cc = 28.6152/3.0;
	const double AA1 = 2.26/cc;
	const double AA2 = 3.33*(2.0/3.0)/aa;
	const double BB1 = 6.86/(cc*cc);
	const double BB2 = 44.5/(aa*aa);
	const double CC1 = 5.74/(cc*cc);
	const double CC2 = 30.4/(aa*aa);
	const double M0 = -0.28 -4*BB2 -2*BB1;
*/
	const int Nx = 1;
	const int Ny = 1;
	const int Nz = 30;
//	const int NSyz = Ny*Nz;
	const int Nl = Nz*4;
	const int ND = Nx*Ny*Nz*4;

	const int Nm = 4;

        const double pi=3.1415926536;
//printf("no error!"); 	
    

	MM0=(double *)malloc(Nm*Nm*2*sizeof(double));
	Tx=(double *)malloc(Nm*Nm*2*sizeof(double));
	Ty=(double *)malloc(Nm*Nm*2*sizeof(double));
	Tz=(double *)malloc(Nm*Nm*2*sizeof(double));
	Txd=(double *)malloc(Nm*Nm*2*sizeof(double));
	Tyd=(double *)malloc(Nm*Nm*2*sizeof(double));
	Tzd=(double *)malloc(Nm*Nm*2*sizeof(double));
	zeeman=(double *)malloc(Nm*Nm*2*sizeof(double));
	


	#include "create_TT_matrices.c"



	xx=(double *)malloc(ND*sizeof(double));
	yy=(double *)malloc(ND*sizeof(double));
	zz=(double *)malloc(ND*sizeof(double));

	for(i=0;i<ND;i++)
	{
		iu = i/4;
		xx[i] = (iu/(Ny*Nz))*aa;
                yy[i] = (iu%Ny)*aa;
                zz[i] = (iu%(Ny*Nz))/Ny*aa;

	//if(zz[i]<1.01*2*cc && zz[i]>0.99*2*cc)   printf("%.3f\t%.3f\n",xx[i],yy[i]);
	}

  
    lwork=2*Nl-1;
   
    M=(double*)malloc(Nl*Nl*2*sizeof(double));
    
    for(kx=-pi/aa;kx<pi/aa;kx+=pi/(aa*20))
    {         

		#include "MM.c"

               w=(double*)malloc(Nl*sizeof(double));
               work=(double*)malloc(2*lwork*sizeof(double));
               rwork=(double*)malloc((3*Nl-2)*sizeof(double));
 
               jobz='N';   
               uplo='U'; 
               lda=Nl;

//               ZHEEV(&jobz,&uplo,&Nl,M,&lda,w,work,&lwork,rwork,&info);
               zheev_(&jobz,&uplo,&Nl,M,&lda,w,work,&lwork,rwork,&info);
             
               free(work);
               free(rwork);
              
               printf("%5f\t",kx);
        i = Nl/2;
               //for(i=0;i<Nl;i++)
               //{
                     printf("%5f\t", w[i]);
   //            }
               printf("\n"); 
             
               free(w); 

     }

   
     free(M); 


	free(xx);
	free(yy);
	free(zz);

	free(MM0);
	free(Tx);
	free(Ty);
	free(Tz);
	free(Txd);
	free(Tyd);
	free(Tzd);
	free(zeeman);



     return 0;
   
       
}

