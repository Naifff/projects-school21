#!/bin/bash

bash build.sh
export DOCKER_CONTENT_TRUST=1
dockle --ignore CIS-DI-0010 -ak NGINX_GPGKEY nyarlath:1.0.0