#include <gtest/gtest.h>
#include<mpi.h>

extern "C" {
#include "mesh.h"
}

TEST(mesh_c, initialise_system_global) {
  GlobalMesh global;
  LocalMesh local;
  initialise_system(10, 11, 12, &local, &global);
  ASSERT_EQ(global.Nx, 10);
  ASSERT_EQ(global.Ny, 11);
  ASSERT_EQ(global.Nz, 10);
}

