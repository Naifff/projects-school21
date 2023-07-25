#!/bin/bash

# validation
function validated_count_param {
    if [ $(($# - 1)) != ${@: -1} ] || [ $# = 0 ]; then
        echo "неправильное количество параметров";
        exit
    fi
}

function validated_path {
    if ! [ -d $1 ]; then
        echo "каталог не существует";
        exit
    elif [ ${1: -1} != "/" ]; then
        echo "путь должен заканчиваться на /";
        exit
    fi
}

function validated_number {
    if [[ !($1 =~ ^[0-9]+$) ]]; then
        echo "параметр должен содержать положительные цифры"
        exit
    fi
}

function validated_letter_in_string {
    if [[ !($1 =~ [[:upper:]] || [[:lower:]])  ]]; then
        echo "параметр должен содержать буквы английского алфавита"
        exit
    fi
}

function validated_len_string {
    string=$1
    if [[ ${#string} -gt $2 ]]; then
        exit
    fi
}

function validated_len_name_files {
    IFS='.' read -ra ADDR <<< "$1"
    if [[ ${#ADDR[@]} != 2 ]]; then
        exit
    fi
    part_1_len=$(echo "${ADDR[0]}" | cut -d '.' -f 1)
    part_2_len=$(echo "${ADDR[1]}" | cut -d '.' -f 2)
    validated_letter_in_string $part_1_len
    validated_len_string $part_1_len 7
    validated_letter_in_string $part_2_len
    validated_len_string $part_2_len 3
}

function validated_count_files_or_folders {
    if [[ $1 = 0 ]]; then
        if [[ $2 = 2 ]]; then
            echo "количство файлов дожно быть больше 0"
            exit
        else
            echo "количство папок дожно быть больше 0"
            exit
        fi
    fi
}

function validated_size {
    if [[ $1 -gt $2 ]]; then
        echo "Размер не должен привышать 100"
        exit
    fi
}

function validated_number_from_too {
    if [[ $1 -lt $2 || $1 -gt $3 ]]; then
        echo "Параметр должен быть от " + $2 + " до " + $3
        exit
    fi
}

function valid_date {
    regular="^[0-9]{2}\/[0-9]{2}\/[0-9]{2}$"
    if [[ !($1 =~ $regular) ]]; then
        echo "Неправильно ведена дата"
        exit
    fi
}

function valid_time {
    regular="^[0-9]{2}:[0-9]{2}:[0-9]{2}$"
    if [[ !($1 =~ $regular) ]]; then
        echo "Неправильно ведено время"
        exit
    fi
}

function valid_part_1 {
    validated_count_param $* 6
    validated_path $1
    validated_number $2
    validated_count_files_or_folders $2 1
    validated_letter_in_string $3
    validated_len_string $3 7
    validated_number $4
    validated_count_files_or_folders $4 2
    validated_len_name_files $5
    validated_size $6 100
    echo "Параметры прошли валидацию"
}

function valid_part_2 {
    validated_count_param $* 3
    validated_letter_in_string $1
    validated_len_string $1 7
    validated_len_name_files $2
    validated_size $3 100
    echo "Параметры прошли валидацию"
}

function valid_part_3 {
    validated_count_param $* 1
    validated_number_from_too $1 1 3
    echo "Параметры прошли валидацию"
}