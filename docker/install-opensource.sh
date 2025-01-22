#!/bin/bash

# 编译的CPU核心数
coreNum=1
if [ $# -ne 0 ]; then
  coreNum=$1
fi

BUILD_DIR=/opt

# 创建构建目录
if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
fi

# 进入构建目录
cd "$BUILD_DIR" || { echo "Failed to enter $BUILD_DIR"; exit 1; }

# 克隆 grpc 仓库
if ! git clone -b v1.34.0 https://gitee.com/mirrors/grpc-framework.git grpc; then
    echo "Failed to clone grpc repository"
    exit 1
fi

# 替换 .gitmodules 文件的内容
cat <<EOF > "$BUILD_DIR/grpc/.gitmodules"
[submodule "third_party/zlib"]
    path = third_party/zlib
    url = https://gitee.com/mirrors/zlib.git
    ignore = dirty
[submodule "third_party/protobuf"]
    path = third_party/protobuf
    url = https://gitee.com/local-grpc/protobuf.git
[submodule "third_party/googletest"]
    path = third_party/googletest
    url = https://gitee.com/local-grpc/googletest.git
[submodule "third_party/benchmark"]
    path = third_party/benchmark
    url = https://gitee.com/mirrors/google-benchmark.git
[submodule "third_party/boringssl-with-bazel"]
    path = third_party/boringssl-with-bazel
    url = https://gitee.com/mirrors/boringssl.git
[submodule "third_party/re2"]
    path = third_party/re2
    url = https://gitee.com/local-grpc/re2.git
[submodule "third_party/cares/cares"]
    path = third_party/cares/cares
    url = https://gitee.com/mirrors/c-ares.git
    branch = cares-1_12_0
[submodule "third_party/bloaty"]
    path = third_party/bloaty
    url = https://gitee.com/local-grpc/bloaty.git
[submodule "third_party/abseil-cpp"]
    path = third_party/abseil-cpp
    url = https://gitee.com/mirrors/abseil-cpp.git
    branch = lts_2020_02_25
[submodule "third_party/envoy-api"]
    path = third_party/envoy-api
    url = https://gitee.com/local-grpc/data-plane-api.git
[submodule "third_party/googleapis"]
    path = third_party/googleapis
    url = https://gitee.com/mirrors/googleapis.git
[submodule "third_party/protoc-gen-validate"]
    path = third_party/protoc-gen-validate
    url = https://gitee.com/local-grpc/protoc-gen-validate.git
[submodule "third_party/udpa"]
    path = third_party/udpa
    url = https://gitee.com/local-grpc/udpa.git
[submodule "third_party/libuv"]
    path = third_party/libuv
    url = https://gitee.com/mirrors/libuv.git
EOF

# 初始化子模块
cd "$BUILD_DIR/grpc" || { echo "Failed to enter grpc directory"; exit 1; }
git submodule update --init --recursive

echo "grpc repository setup completed successfully."

# 构建 grpc
mkdir -p cmake/build
cd cmake/build || { echo "Failed to enter build directory"; exit 1; }

# 使用 CMake 配置 grpc
cmake ../.. -DgRPC_INSTALL=ON -DCMAKE_INSTALL_PREFIX=/usr/local || { echo "CMake configuration failed"; exit 1; }

# 编译 grpc
make -j$coreNum || { echo "Make failed"; exit 1; }

# 安装 grpc
sudo make install || { echo "Make install failed"; exit 1; }

echo "grpc installation completed successfully."

# 进入 Protobuf 目录并构建 Protobuf
cd "$BUILD_DIR/grpc/third_party/protobuf" || { echo "Failed to enter protobuf directory"; exit 1; }

# 生成配置脚本
./autogen.sh || { echo "Autogen failed"; exit 1; }

# 配置 Protobuf
./configure --prefix=/usr/local || { echo "Configure failed"; exit 1; }

# 编译 Protobuf
make -j$coreNum || { echo "Protobuf make failed"; exit 1; }

# 安装 Protobuf
sudo make install || { echo "Protobuf make install failed"; exit 1; }

# 更新动态库缓存
sudo ldconfig || { echo "ldconfig failed"; exit 1; }

echo "Protobuf installation completed successfully."