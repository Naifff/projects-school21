#!/bin/bash
FILE=work.sh
chmod +rx $FILE
if [ ! -f $FILE ]; then
    echo Ошибка: файл не существует: $FILE
    exit
fi
if [ $# != 1 ] || [ $# = 0 ]; then
    echo "должен быть один параметр";
elif ! [ -d $1 ]; then
    echo "каталог не существует";
elif [ ${1: -1} != "/" ]; then
    echo "путь должен заканчиваться на /";
else
    ./work.sh $1
    echo "Script execution time (in seconds) = $SECONDS"
fi