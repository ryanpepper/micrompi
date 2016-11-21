#include<stdio.h>
#include<stdlib.h>
#include "mesh.h"
#include "mpi.h"

void initialise_system(const int N[3], const int d[3], const int periodic[],
                       LocalMesh *local, GlobalMesh *global, MPI_Comm COMMUNICATOR) {
  
  MPI_Comm_size(COMMUNICATOR, &global->procs);
  global->N[0] = N[0];
  global->N[1] = N[1];
  global->N[2] = N[2];
  
  if (N[1] == 0 && N[2] == 0) {
    global->dim = 1;
  }
  else if (N[2] == 0) {
    global->dim = 2;
  }
  else {
    global->dim = 3;
  }
 
  global->MPI_dims = malloc(sizeof(int)*global->dim);
  for (int i = 0; i < global->dim; i++) {
    global->MPI_dims[i] = 0;
  }
  
  printf("global->dim = %d \n", global->dim);  

  MPI_Dims_create(global->procs, global->dim, global->MPI_dims);
  int rank, errorcode;
  errorcode = MPI_Comm_rank(COMMUNICATOR, &rank);
  printf("Rank = %d", rank);
  if(errorcode) {
    printf("Error in mesh.c: initialise_system: MPI_Comm_rank failed with errorcode %d", 
           errorcode);
  }
  errorcode = MPI_Cart_create(COMMUNICATOR, global->dim, global->MPI_dims, 
                  periodic, 0, global->comm);
  if(errorcode) {
    printf("Error in mesh.c: initialise_system: MPI_Cart_create failed with errorcode %d",
           errorcode);
  }
}
