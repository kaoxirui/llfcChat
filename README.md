# llfcChat
llfc全栈聊天项目

# 第三方库

```shell
# hiredis
sudo apt-get install libhiredis-dev

# mysqlconnector_c++
sudo apt install default-libmysqlclient-dev

# protobuf + grpc [参考](https://llfc.club/category?catid=225RaiVNI8pFDD5L4m807g7ZwmF#!aid/2eIaoR0NBxxirmXKdzcke9vJxmP)

# jsoncpp 1.92 下载源码 到build文件夹 cmake .. --> make -j6 && make install

# boost
sudo apt-get install libboost-dev libboost-test-dev libboost-all-dev
```

# 环境搭建

参考博主的grpc环境搭建，下载grpc到docker/install/grpc下，保存为压缩包，在docker里构建grpc环境

nodejs环境不知道怎么在dockerfile中构建在VarifyServer下，直接在docker环境里安装要用的包，然后保存为新的镜像

```shell
mysql密码设置

ALTER USER 'root'@'localhost' IDENTIFIED BY 'your_new_password';
FLUSH PRIVILEGES;

mysql启动

service mysql start

登录

mysql -u root -p

navicat连不上docker里的mysql？

localhost改成宿主机的IP
```
```shell
启动redis：redis-server /etc/redis/redis.conf

停止redis：service redis-server stop
```

redis-server /etc/redis/redis.conf

proto文件生成

 protoc --grpc_out=. --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin message.proto

 protoc --cpp_out=. message.proto

| 2025_1_15     | QT界面搭建，jsoncpp库安装      |
| ------------- | ------------------------------ |
| **2025_1_16** | **beast搭建HTTP服务器**        |
| **2025_1_18** | **处理POST请求并解析json数据** |
| **2025_1_21** | **docker环境即其他部分**       |

