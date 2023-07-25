#!/bin/bash
if [ $# = 1 ]; then
    check="[^а-яА-Яa-zA-Z]"
    if [[ $1 =~ $check ]]; then
        echo "параметр должен содержать буквы";
    else
        echo $1;
    fi
elif [ $# \> 1 ]; then
    echo "недолжно быть больше одного параметра";
else
    echo "ведите текстовый параметр";
fi