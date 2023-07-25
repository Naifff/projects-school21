#!/bin/bash
FILE=../functions.sh
chmod +rx $FILE
if [ ! -f $FILE ]; then
    echo Ошибка: файл не существует: $FILE
    exit
fi
source ../functions.sh
set_date
get_info
save_file