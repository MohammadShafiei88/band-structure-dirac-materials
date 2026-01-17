Band Structure Calculation for Dirac Materials

This repository contains a C implementation for calculating the energy spectrum (band structure) of topological insulators and Dirac materials, specifically optimized for the Bi2Se3 family.

Features
Model: Implements the 4-band effective Hamiltonian for Bi2Se3 type materials.

Geometry: Supports slab geometry (Nz layers) to investigate surface states and bulk properties.

Method: Uses the Tight-Binding approximation with nearest-neighbor hopping matrices (Tx,Ty,Tz).

Solver: Utilizes the zheev routine from the LAPACK/Accelerate framework for efficient Hermitian matrix diagonalization.

Physics Parameters
The code uses standard parameters for Dirac materials:

AA: Spin-orbit coupling / linear momentum term.

BB: Quadratic correction (Mass term curvature).

MM: Mass parameter (determines the topological regime).

delta: Zeeman coupling or symmetry-breaking terms.

File Structure
Bi2Se3_band_structure.c: Main driver script that sets up the lattice and iterates over momentum (k).

create_TT_matrices.c: Definition of the onsite energy and hopping matrices (4×4).

MM.c: Construction of the full Hamiltonian matrix M including periodic phases.
