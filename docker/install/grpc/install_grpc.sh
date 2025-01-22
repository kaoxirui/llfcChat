
#!/usr/bin/env bash

set -e

cd "$(dirname "${BASH_SOURCE[0]}")"

THREAD_NUM=$(nproc)


VERSION="1.34.0"
PKG_NAME="grpc-${VERSION}.tar.gz"

tar xzf "${PKG_NAME}"
pushd grpc-${VERSION}
    mkdir build && cd build

    cmake .. \
        -DBUILD_SHARED_LIBS=ON \
        -DCMAKE_INSTALL_PREFIX:PATH="/usr/local" \
        -DCMAKE_BUILD_TYPE=Release

    make -j$(nproc)
    make install
popd

ldconfig

# Clean up
rm -rf PKG_NAME grpc-${VERSION} "${PKG_NAME}"
