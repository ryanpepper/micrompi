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

void initialise_system(int Nx, int Ny, int Nz, LocalMesh *local, GlobalMesh *global) {
  global->Nx = Nx;
  global->Ny = Ny;
  global->Nz = Nz;
  int rank, errorcode;
  errorcode = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  #ifdef DEBUG
  if(errorcode) {
    printf("Error in mesh.c: initialise_system: MPI_Comm_rank failed with errorcode %d", 
           errorcode);
  }
  #endif
}
