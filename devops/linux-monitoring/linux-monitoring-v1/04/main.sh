#!/bin/bash
FILES=(../functions.sh parameters.conf)
for FILE in $FILES
do
    chmod +rx $FILE
    if [ ! -f $FILE ]; then
        echo Ошибка: файл не существует: $FILE
        exit
    fi
done
source ../functions.sh
set_date
b1=$(set_parameters column1_background)
c1=$(set_parameters column1_font_color)
b2=$(set_parameters column2_background)
c2=$(set_parameters column2_font_color)
if [ $b1 -eq $c1 ]; then
    b1=0
    c1=0
elif [ $b2 -eq $c2 ]; then
    b2=0
    c2=0
fi
get_info $(get_bgcolor 1 $b1) $(get_color 1 $c1) $(get_bgcolor 2 $b2) $(get_color 2 $c2) $normal
get_names_color $b1 $c1 $b2 $c2 