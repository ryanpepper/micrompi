#include<stdio.h>
#include<stdlib.h>
#include "mesh.h"
#include "mpi.h"

int initialise_system(const int N[3], const double d[3], const int periodic[3],
                       LocalMesh *local, GlobalMesh *global, MPI_Comm COMMUNICATOR) {
  
  MPI_Comm_rank(COMMUNICATOR, &global->rank);
  MPI_Comm_size(COMMUNICATOR, &global->procs);
  memcpy(global->N, N, sizeof(int)*3);
  memcpy(global->d, d, sizeof(double)*3);
  memcpy(global->periodic, periodic, sizeof(int)*3);
  for(int i = 0; i < 3; i++) {
    global->MPI_dims[i] = 0;
  }
  if (N[1] == 0 && N[2] == 0) {
    global->dim = 1;
  }
  else if (N[2] == 0) {
    global->dim = 2;
  }
  else {
    global->dim = 3;
  }

  int checkdims = 0;
  if (global->dim == 1) {
    if (d[0] <= 0) { 
      fprintf(stderr, "Error in mesh.h/initialise_system: Discretisation values d must be non-zero\n");
      return -1;
    }
  }

  else if (global->dim == 2) {
    if (d[0] <= 0 || d[1] <= 0) { 
      fprintf(stderr, "Error in mesh.h/initialise_system: Discretisation values d must be non-zero");
      return -1;
    }
  }
  
  else {
    if (d[0] <= 0 || d[1] <= 0 || d[2] <= 0) { 
      fprintf(stderr, "Error in mesh.h/initialise_system: Discretisation values d must be non-zero");
      return -1;
    }
  }
 
  
  #ifdef MICROMPI_TRACE
    if (global->rank == 0) {
      printf("DEBUG: global->dim = %d", global->dim);
      for(int i = 0; i<3; i++) {
        printf("DEBUG: N[%d] = %d \n", i, N[i]);
        printf("DEBUG: global->N[%d] = %d \n", i, global->N[i]);
      }
    }
  #endif

  MPI_Dims_create(global->procs, global->dim, global->MPI_dims);
  
  printf("Dims Create worked");
  #ifdef MICROMPI_TRACE
    if (global->rank == 0) {
      for(int i = 0; i<3; i++) {
        printf("DEBUG: N[%d] = %d \n", i, N[i]);  
        printf("DEBUG: global->MPI_dims[%d] = %d \n", i, global->MPI_dims[i]);
        printf("DEBUG: global->periodic[%d] = %d \n", i, global->periodic[i]);
      }
    }
  #endif
  printf("PRINTING Dims create worked!");
  int errorcode;
  
  errorcode = MPI_Cart_create(COMMUNICATOR, global->dim, global->MPI_dims, 
                  periodic, 0, global->comm);


  if(errorcode) {
    printf("Error in mesh.h/initialise_system: MPI_Cart_create failed with errorcode %d",
           errorcode);
    return -1;
  }
  printf("Got here!");
  return 0;
}
