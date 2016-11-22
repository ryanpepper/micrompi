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
  int N[3] = {10, 0, 0}; // All values other than first are ignored
  double d[3] = {1, 0, 0};
  int periodic[3] = {0, 0, 0};
  int dim = 1;
  initialise_system(dim, N, d, periodic, &local, &global, MPI_COMM_WORLD);
  ASSERT_EQ(global.N[0], 10);
  ASSERT_EQ(global.N[1], 1);
  ASSERT_EQ(global.N[2], 1);
  ASSERT_EQ(global.dim, 1);
  ASSERT_EQ(global.MPI_dims[0], size);
}



TEST(mesh_c, initialise_system_global_2D) {
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  GlobalMesh global;
  LocalMesh local;
  int N[3] = {10, 9, 0};
  double d[3] = {1, 1, 0};
  int periodic[3] = {0, 0, 0};
  int dim = 2;
  initialise_system(dim, N, d, periodic, &local, &global, MPI_COMM_WORLD);
  ASSERT_EQ(global.N[0], 10);
  ASSERT_EQ(global.N[1], 9);
  ASSERT_EQ(global.N[2], 0);
  ASSERT_EQ(global.dim, 2);
}

TEST(mesh_c, initialise_system_global_3D) {
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  GlobalMesh global;
  LocalMesh local;
  int N[3] = {10, 9, 8};
  double d[3] = {1, 1, 1};
  int periodic[3] = {0, 0, 0};
  int dim = 3;
  initialise_system(dim, N, d, periodic, &local, &global, MPI_COMM_WORLD);
  ASSERT_EQ(global.N[0], 10);
  ASSERT_EQ(global.N[1], 9);
  ASSERT_EQ(global.N[2], 8);
  ASSERT_EQ(global.dim, 3);
}