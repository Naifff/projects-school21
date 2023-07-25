#!/bin/bash

SERVER_ADDRESS=root@192.0.2.3

REMOTE_DIR=/usr/local/bin/

scp src/cat/s21_cat src/grep/s21_grep $SERVER_ADDRESS:$REMOTE_DIR
