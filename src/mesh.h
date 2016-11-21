#define DEBUG
#include<stdio.h>
#include<string.h>
#include<mpi.h>

typedef struct GlobalMesh {
  int dim;
  int N[3];
  int procs;
  int rank;
  int* MPI_dims;
  MPI_Comm *comm;
} GlobalMesh;

typedef struct LocalMesh { 
  int nx, ny, nz;
  double *m;
} LocalMesh;

void initialise_system(const int N[3], const int d[3], const int periodic[],
                       LocalMesh *local, GlobalMesh *global, MPI_Comm COMMUNICATOR);
