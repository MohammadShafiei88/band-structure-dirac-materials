
for(i=0;i<Nm;i++)
{
	for(j=0;j<Nm;j++)
	{
		Tx[2*(Nm*j+i)]    =0.0;
		Tx[2*(Nm*j+i)+1]  =0.0;
		Ty[2*(Nm*j+i)]    =0.0;
		Ty[2*(Nm*j+i)+1]  =0.0;
		Tz[2*(Nm*j+i)]    =0.0;
		Tz[2*(Nm*j+i)+1]  =0.0;	
		zeeman[2*(Nm*j+i)]    =0.0;
		zeeman[2*(Nm*j+i)+1]  =0.0;

        Txd[2*(Nm*j+i)]    =0.0;
		Txd[2*(Nm*j+i)+1]  =0.0;
		Tyd[2*(Nm*j+i)]    =0.0;
		Tyd[2*(Nm*j+i)+1]  =0.0;
		Tzd[2*(Nm*j+i)]    =0.0;
		Tzd[2*(Nm*j+i)+1]  =0.0;
	
		
		MM0[2*(Nm*j+i)]    =0.0;
		MM0[2*(Nm*j+i)+1]  =0.0;
	}
}



Tx[0]  = BB;
Tx[25]  = -0.5*AA;
Tx[10] = -BB;
Tx[19] = -0.5*AA;
Tx[13] = -0.5*AA;
Tx[20] = BB;
Tx[7] = -0.5*AA;
Tx[30] = -BB;

Ty[0]  = BB;
Ty[24]  = -0.5*AA;
Ty[10] = -BB;
Ty[18] = -0.5*AA;
Ty[12] = 0.5*AA;
Ty[20] = BB;
Ty[6] = 0.5*AA;
Ty[30] = -BB;


Tz[0]  = BB;
Tz[9]  =-0.5*AA;
Tz[3]  = -0.5*AA;
Tz[10] = -BB;
Tz[20] = BB;
Tz[29] = 0.5*AA;
Tz[23] = 0.5*AA;
Tz[30] = -BB;



Txd[0]  = BB;
Txd[25]  = 0.5*AA;
Txd[10] = -BB;
Txd[19] = 0.5*AA;
Txd[13] = 0.5*AA;
Txd[20] = BB;
Txd[7] = 0.5*AA;
Txd[30] = -BB;

Tyd[0]  = BB;
Tyd[24]  = 0.5*AA;
Tyd[10] = -BB;
Tyd[18] = 0.5*AA;
Tyd[12] = -0.5*AA;
Tyd[20] = BB;
Tyd[6] = -0.5*AA;
Tyd[30] = -BB;


Tzd[0]  = BB;
Tzd[9]  = 0.5*AA;
Tzd[3]  = 0.5*AA;
Tzd[10] = -BB;
Tzd[20] = BB;
Tzd[29] = -0.5*AA;
Tzd[23] = -0.5*AA;
Tzd[30] = -BB;




MM0[0]  = MM-6*BB1 + delta;
MM0[10] =-(MM-6*BB1) + delta;
MM0[20] = MM-6*BB1 - delta;
MM0[30] =-(MM-6*BB1) - delta;

zeeman[0]  = delta ;
zeeman[10] = delta;
zeeman[20] = -delta;
zeeman[30] = -delta;
 

