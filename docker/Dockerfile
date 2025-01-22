FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive
WORKDIR /opt

RUN apt-get update && apt-get install -y --no-install-recommends \
        software-properties-common \
        curl apt-utils openssl build-essential ca-certificates pkg-config libglib2.0-dev valgrind \
        gdb vim automake autoconf libtool sudo git g++ gcc make libssl-dev dos2unix \
        libfmt-dev libssl-dev libevent-dev libdouble-conversion-dev libzstd-dev liblz4-dev \
        libsnappy-dev libjemalloc-dev \  
        libmsgpack-dev \
        lcov wget zlib1g zlib1g-dev libncurses5-dev liblzma-dev cmake \
        libboost-all-dev \
        python3 python3-pip && \
        python3 -m pip install --upgrade pip -i https://pypi.tuna.tsinghua.edu.cn/simple && \
        update-alternatives --install /usr/bin/python python /usr/bin/python3 1 && \
        add-apt-repository ppa:ubuntu-toolchain-r/test && \
        apt-get update && apt-get install -y --no-install-recommends \
        gcc-10 \
        g++-10 && \
        update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 100 && \
        update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 100 && \
        apt-get clean -y



RUN echo "deb http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse" > /etc/apt/sources.list && \
    echo "deb http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse" >> /etc/apt/sources.list && \
    echo "deb http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse" >> /etc/apt/sources.list && \
    echo "deb http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse" >> /etc/apt/sources.list && \
    apt-get update

# #=== opensource
# COPY install-opensource.sh /opt/install-opensource.sh
# RUN dos2unix /opt/install-opensource.sh && chmod +x /opt/install-opensource.sh && /opt/install-opensource.sh
COPY install/grpc /tmp/install/grpc

RUN chmod +x /tmp/install/grpc/install_grpc.sh
RUN bash /tmp/install/grpc/install_grpc.sh

# 安装 Node.js 和 npm
RUN apt-get update && \
    apt-get install -y curl gnupg2 lsb-release ca-certificates && \
    curl -fsSL https://deb.nodesource.com/setup_16.x | bash - && \
    apt-get install -y nodejs

# 安装 Redis 依赖
RUN apt-get update && \
    apt-get install -y redis-server redis-tools libjsoncpp-dev
# 安装 Qt5 库和其他依赖
RUN apt-get update && apt-get install -y \
    libqt5widgets5 \
    libqt5core5a \
    libqt5gui5 \
    qtbase5-dev qttools5-dev-tools libhiredis-dev\
    && rm -rf /var/lib/apt/lists/*

RUN apt update && apt install -y fonts-wqy-zenhei fonts-wqy-microhei

    # 设置动态库路径
ENV LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu

# COPY scripts/init_npm.sh /tmp/init_npm.sh
# RUN chmod +x /tmp/init_npm.sh
# RUN bash /tmp/init_npm.sh
#=== 清理缓存文件
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*


