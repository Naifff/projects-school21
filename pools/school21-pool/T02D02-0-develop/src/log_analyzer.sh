#!/bin/bash/

echo "Введите путь до log файла"

read path_file

count=$(wc -l $path_file | awk '{ print $1 }')
uniq1=$(sort -k1 $path_file | awk '{ print $1 }'| uniq | wc -l | awk '{ print $1 }')

echo "$count $uniq1 $count"
