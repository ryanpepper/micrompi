#include "mesh.h"

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
