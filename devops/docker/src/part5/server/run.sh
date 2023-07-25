#!/bin/bash
gcc server.c -o server -lfcgi 
spawn-fcgi -p 8080 ./server 
nginx -s reload
nginx -g 'daemon off;'
