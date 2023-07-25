#!/bin/bash

./clear_docker.sh

docker build -t nyarlath:1.0.0 .
docker run -d -p 80:81 --name server nyarlath:1.0.0

sleep 1

printf "\n\n"
curl localhost:80
printf "\n\n"
curl localhost:80/status
printf "\n\n"