#!/bin/bash
FILE=../functions.sh
chmod +rx $FILE
if [ ! -f $FILE ]; then
    echo Ошибка: файл не существует: $FILE
    exit
fi
source ../functions.sh
set_date
if [ $# -eq 4 ]; then
    for var in $#
    do
        validated_parameters $var
    done
    if [ $1 -eq $2 ] || [ $3 -eq $4 ]; then
        echo "параметры не должны быть равны"
    else
        get_info $(get_bgcolor 1 $1) $(get_color 1 $2) $(get_bgcolor 2 $3) $(get_color 2 $4) $normal
    fi
elif [ $# \> 4 ]; then
    echo "недолжно быть больше четырех параметров";
else
    echo "ведите четыре параметра от 1 до 6";
fi