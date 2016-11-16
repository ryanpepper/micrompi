#define DEBUG
#include<stdio.h>
#include<string.h>
#include<mpi.h>

typedef struct GlobalMesh {
  int Nx, Ny, Nz;
  int procs;
  int rank;
} GlobalMesh;

typedef struct LocalMesh { 
  int nx, ny, nz;
  double *m;
} LocalMesh;

void initialise_system(int Nx, int Ny, int Nz, LocalMesh *local, GlobalMesh *global);
