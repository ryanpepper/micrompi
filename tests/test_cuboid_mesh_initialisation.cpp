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
  int d[3] = {1, 0, 0};
  int periodic[3] = {0, 0, 0};
  initialise_system(N, d, periodic, &local, &global, MPI_COMM_WORLD);
  ASSERT_EQ(global.N[0], 10);
  ASSERT_EQ(global.N[1], 0);
  ASSERT_EQ(global.N[2], 0);
  ASSERT_EQ(global.dim, 1);
  ASSERT_EQ(global.MPI_dims[0], size);
}

