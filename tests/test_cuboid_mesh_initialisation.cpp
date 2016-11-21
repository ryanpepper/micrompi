#include <gtest/gtest.h>
#include "mpi.h"

extern "C" {
#include "mesh.h"
}

TEST(mesh_c, initialise_system_global_1D) {
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  GlobalMesh global;
  LocalMesh local;
  int N[3] = {10, 0, 0};
  double d[3] = {1, 0, 0};
  int periodic[3] = {0, 0, 0};
  initialise_system(N, d, periodic, &local, &global, MPI_COMM_WORLD);
  ASSERT_EQ(global.N[0], 10);
  ASSERT_EQ(global.N[1], 0);
  ASSERT_EQ(global.N[2], 0);
  ASSERT_EQ(global.dim, 1);
  ASSERT_EQ(global.MPI_dims[0], size);
}

TEST(mesh_c, initialise_system_incorrect_discretisations_check_return_code) {
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  GlobalMesh global;
  LocalMesh local;
  int N_1[3] = {10, 0, 0};
  int N_2[3] = {10, 10, 0};
  int N_3[3] = {10, 10, 10};
  double d[3] = {0, 0, 0};
  int periodic[3] = {0, 0, 0};
  // Check that error returned for systems when d values are zero. 
  ASSERT_EQ(initialise_system(N_1, d, periodic, &local, &global, MPI_COMM_WORLD), -1);
  ASSERT_EQ(initialise_system(N_2, d, periodic, &local, &global, MPI_COMM_WORLD), -1);
  ASSERT_EQ(initialise_system(N_3, d, periodic, &local, &global, MPI_COMM_WORLD), -1);
}

TEST(mesh_c, initialise_system_global_2D) {
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  GlobalMesh global;
  LocalMesh local;
  int N[3] = {10, 9, 0};
  double d[3] = {1, 0, 0};
  int periodic[3] = {0, 0, 0};
  initialise_system(N, d, periodic, &local, &global, MPI_COMM_WORLD);
  ASSERT_EQ(global.N[0], 10);
  ASSERT_EQ(global.N[1], 9);
  ASSERT_EQ(global.N[2], 0);
  ASSERT_EQ(global.dim, 2);
}
