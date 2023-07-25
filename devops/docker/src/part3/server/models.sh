#!/bin/bash

server_name="server3"

function checkDocker {
    sudo docker --help 2>/dev/null  1> check.tmp
    if ! [[ $(cat check.tmp | grep "A self-sufficient runtime for containers") ]]; then
        # Delete all docker files from the space of a user
        sudo apt-get purge -y docker-engine docker docker.io docker-ce docker-ce-cli docker-compose-plugin
        sudo apt-get autoremove -y --purge docker-engine docker docker.io docker-ce docker-compose-plugin
        sudo rm -rf /var/lib/docker /etc/docker 2>/dev/null
        sudo rm /etc/apparmor.d/docker 2>/dev/null
        sudo groupdel docker 2>/dev/null
        sudo rm -rf /var/run/docker.sock 2>/dev/null
        # Install all necessary utilities for Docker
        sudo apt-get update
        sudo apt-get install ca-certificates curl gnupg lsb-release
        sudo mkdir -m 0755 -p /etc/apt/keyrings
        curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
        echo \
        "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
        $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
        # Install Docker
        sleep 5
        sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
        sleep 5
        sudo docker run hello-world 1> check.tmp
        if [[ ! $(cat check.tmp | grep "Hello from Docker!") ]]; then
            echo "\n\nSomething was wrong. Try again.\n\n"
            exit
        else
            printf "\n\n\nDocker is running\n\n\n"
        fi
    else
        printf "\n\n\nDocker is running\n\n\n"
    fi
    rm -rf check.tmp
}

function issuLicense {
    printf "\n\n"
    echo "Выдача прав на докер"
    echo $USER
    sudo usermod -aG docker $USER
    sudo usermod -aG docker $USER
}

function pullNginx {
    check_image=$(sudo docker images)
    if [[ $check_image != *"nginx"* ]]; then
        printf "\n\n"
        echo "docker образ устанавливается"
        sudo docker pull nginx
    fi
}

function runContainer {
    check_container=$(sudo docker ps)
    printf "\n\n"
    echo "запускается контейнер"
    if [[ $check_container != *$server_name* ]]; then
        sudo docker run -dit -p 81:81 --name $server_name nginx:latest
    fi
    sudo docker ps
}

function cpServerFCGI {
    printf "\n\n"
    echo "Перенос файла в контейнер"
    sudo docker cp server.c $server_name:/
    printf "\n\n"
    echo "Апдейт системы"
    sudo docker exec $server_name apt-get update 
    sudo docker exec $server_name apt-get upgrade 
    declare -a packages=("spawn-fcgi" "libfcgi-dev" "gcc")
    for package in "${packages[@]}"
    do
        printf "\n\n"
        echo "Установка пакетов $package"
        sudo docker exec $server_name apt-get install -y $package
    done
    printf "\n\n"
    echo "Компиляция файла"
    sudo docker exec $server_name gcc server.c -o server -lfcgi
    echo "Запуск сервера"
    docker exec $server_name spawn-fcgi -p 8080 ./server
}

function cpNginxConf {
    printf "\n\n"
    echo "Перенос nginx.conf в контейнер"
    sudo docker cp nginx.conf $server_name:/etc/nginx/conf.d/default.conf
    sudo docker exec $server_name nginx -s reload
    nginx_status=$(sudo docker exec $server_name service nginx status)
    if [[ $nginx_status != *"is running"* ]]; then
        sudo docker exec $server_name service nginx start
    fi
    printf "\n\n"
    echo "Чек сайта"
    curl localhost:81
}
