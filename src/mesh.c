#include<stdio.h>
#include<stdlib.h>
#include "mesh.h"
#include "mpi.h"

int initialise_system(const int dim, const int N[3], const double d[3], const int periodic[3],
                       LocalMesh *local, GlobalMesh *global, MPI_Comm COMMUNICATOR) {
  // initialise_system: 
  // This function sets up all of the data storage type stuff; e.g
  // allocating memory for the magnetisation field to be stored in,
  // etc.
  global->dim = dim;
  MPI_Comm_rank(COMMUNICATOR, &global->rank);
  MPI_Comm_size(COMMUNICATOR, &global->procs);
  memcpy(global->N, N, sizeof(int)*3);
  memcpy(global->d, d, sizeof(double)*3);
  memcpy(global->periodic, periodic, sizeof(int)*3);
  
  for(int i = 0; i < 3; i++) {
    global->MPI_dims[i] = 0;
  }
  for(int i=dim+1; i < 3; i++) {
    global->N[i] = 1;
    global->d[i] = 0;
  }
  
  
  

  MPI_Dims_create(global->procs, global->dim, global->MPI_dims);
  printf("DEBUG: global->MPI_dims = %d %d %d\n", global->MPI_dims[0], global->MPI_dims[1], global->MPI_dims[2]);
  
  int errorcode;
  
  errorcode = MPI_Cart_create(COMMUNICATOR, global->dim, global->MPI_dims, 
                  periodic, 0, global->comm);


  if(errorcode) {
    printf("Error in mesh.h/initialise_system: MPI_Cart_create failed with errorcode %d",
           errorcode);
    return -1;
  }

  local->m = malloc(sizeof(double)*N[0]);
  return 0;
}

