#!/usr/bin/env bash

#只执行docker run，里面没有内容，需要将本机的内容映射到容器中
MONITOR_HOME_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"
#"$( dirname "${BASH_SOURCE[0]}"=/home/kao/work/ros_protobuf_msg/docker/scripts
#"$( dirname "${BASH_SOURCE[0]}" )/../.."=/home/kao/work/ros_protobuf_msg
#pwd 显示出路径
display=""
if [ -z ${DISPLAY} ];then
    display=":1"
else
    display="${DISPLAY}"
fi
#display为了qt显示

#本质是和宿主机的文件属性一致
local_host="$(hostname)"
user="${USER}"
uid="$(id -u)"
group="$(id -g -n)"
gid="$(id -g)"

#一个容器名只能启动一次，所以要先清除再启动
echo "stop and rm docker" 
docker stop llfcchat > /dev/null
docker rm -v -f llfcchat > /dev/null

echo "start docker"
docker run -it -d \
--privileged=true \
--name llfcchat \
-e DISPLAY=$display \
-e DOCKER_USER="${user}" \
-e USER="${user}" \
-e DOCKER_USER_ID="${uid}" \
-e DOCKER_GRP="${group}" \
-e DOCKER_GRP_ID="${gid}" \
-e XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR \
-v ${MONITOR_HOME_DIR}:/opt \
-v ${XDG_RUNTIME_DIR}:${XDG_RUNTIME_DIR} \
-v /home/kao/cpp/llfcChat/mysql/config/my.cnf:/etc/mysql/my.cnf \
-v /home/kao/cpp/llfcChat/mysql/data/:/var/lib/mysql \
-v /home/kao/cpp/llfcChat/mysql/logs:/logs \
--network host \
llfcchat:v4
#-p 3308:3306 \

# -v挂载  -e指定容器内的环境变量
# -it交互  -d后台运行（不会影响此时的终端）
#--network host \ 使用主机网络栈，不需要也不能进行端口映射
