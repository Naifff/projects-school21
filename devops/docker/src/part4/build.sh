#!/bin/bash

docker build -t nyarlath:latest .

check_image=$(docker images)

if [[ $check_image != *"nyarlath"* ]]; then
    echo "docker образ не установлен"
    exit
fi

docker run -d -p 80:81 nyarlath

sleep 1

printf "\n\n"
curl localhost:80
printf "\n\n"
curl localhost:80/status
printf "\n\n"