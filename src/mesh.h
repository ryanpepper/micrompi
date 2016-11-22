#define DEBUG
#include<stdio.h>
#include<string.h>
#include<mpi.h>

typedef struct GlobalMesh {
  int dim;
  int N[3];
  double d[3];
  int periodic[3];
  int size;
  int procs;
  int rank;
  int MPI_dims[3];
  MPI_Comm *comm;
} GlobalMesh;

typedef struct LocalMesh { 
  int nx, ny, nz;
  double *m;
} LocalMesh;

int initialise_system(const int dim, const int N[3], const double d[3], const int periodic[],
                      LocalMesh *local, GlobalMesh *global, MPI_Comm COMMUNICATOR);


int set_m(void (*f)(double r[3], double m[3]));