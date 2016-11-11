RELEASE=release-1.8.0
HERE_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

CXXDIR="$(dirname "$HERE_DIR")"
LIBS_DIR=${CXXDIR}/local
mkdir -p ${LIBS_DIR}

CC=icpc
MPI_CC=mpicxx

wget https://github.com/google/googletest/archive/${RELEASE}.tar.gz
tar -xvf ${RELEASE}.tar.gz -C ${LIBS_DIR}
cd ${LIBS_DIR}/googletest-${RELEASE} && cmake . && make

