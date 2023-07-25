#!/bin/bash

# include
source ../validation.sh

function part_1 {
    path=$1
    count_folder=$2
    list_letter_folder=$3
    count_files=$4
    list_letter_files=$5
    size=$6
    valid_part_1 $*
    algorithm $* 1 part_1.log
}

function part_2 {
    valid_part_2 $*
    list_letter_folder=$1
    list_letter_files=$2
    size=$3
    path=$(random_path)/
    count_folder=$((RANDOM % 100))
    count_files=$((RANDOM % 100))
    algorithm 2 part_2.log
}

function part_3 {
    valid_part_3 $*
    if [[ $1 -eq 1 ]]; then
        for var in $(find $(cd ../ && pwd) | grep .log)
        do
            while IFS= read -r line; do
                sudo rm -rf $(echo "$line" | awk '{print $1}')
            done < $var
        done
    elif [[ $1 -eq 2 ]]; then
        #Получение даты
        read -p "Введите дату начала: " dateAndTimeFrom
        valid_date $(echo $dateAndTimeFrom | awk '{print $1}')
        valid_time $(echo $dateAndTimeFrom | awk '{print $2}')
        read -p "Введите дату начала: " dateAndTimeTo
        valid_date $(echo $dateAndTimeTo | awk '{print $1}')
        valid_time $(echo $dateAndTimeTo | awk '{print $2}')
        for var in $(find $(cd ../ && pwd) | grep .log)
        do
            while IFS= read -r line; do
                dateLine=$(echo "$line" | awk '{printf("%s %s", $2, $3)}')
                dateL=$(date -d "$dateLine" +%s)
                if [[ $dateL -ge $(date -d "$dateAndTimeFrom" +%s) && $dateL -le $(date -d "$dateAndTimeTo" +%s) ]]; then
                    sudo rm -rf $(echo "$line" | awk '{print $1}')
                fi
            done < $var
        done
    elif [[ $1 -eq 3 ]]; then
        regular="^.*[a-zA-Z]*_([0-9]{2})([0-9]{2})([0-9]{2})$"
        for var in $(find $(cd ../ && pwd) | grep .log)
        do
            while IFS= read -r line; do
                if [[ $(echo "$line" | awk '{print $1}') =~ $regular ]]; then
                    sudo rm -rf $(echo "$line" | awk '{print $1}')
                fi
            done < $var
        done
    fi
}

function random_path {
    mapfile -t arr_dirs < <(sudo find / -type d -writable 2> /dev/null | grep -vE '/(bin|sbin|sys|proc|dev|snap)/?')
    count_dirs=${#arr_dirs[@]}
    random_index=$((RANDOM % count_dirs))
    random_path=${arr_dirs[random_index]}
    echo $random_path
}

function algorithm {
    path_log=${@: -1}
    part=${@: -2} 
    generation $path_log $part
}

function generation {
    #создание логера
    create_log_file $1

    #локальные переменные
    count_create_folders=0
    count_create_files=0
    count_f=1
    count_fi=1

    generate_folders $1 $2
}

#генерация папок
function generate_folders {
    while [ $count_create_folders != $count_folder ]
    do
        for (( i=0; $i<${#list_letter_folder}; i=$(($i+1)) ))
        do
            name_folder=""
            for (( j=0; $j<${#list_letter_folder}; j=$(($j+1)) ))
            do
                if [[ $i = $j ]]; then
                    for (( k=1; $k<$(($count_f+1)); k=$(($k+1)) ))
                    do
                        name_folder+=${list_letter_folder:$j:1}
                    done
                else
                    name_folder+=${list_letter_folder:$j:1}
                fi
            done
            Day="_$(date +%d%m)$(date | awk '{print $NF}' | awk '{print substr($0,3,2)}')"
            name_folder+=$Day
            path_foleder=$path$name_folder
            if [[ ${#path_foleder} -le 255 ]]; then
            # проверка на минимум 4 символа в папке
                if [[ ${#name_folder} -ge 4 ]]; then
                    #проверка на существование уже этой папки
                    if ! [ -d $path_foleder ]; then
                        sudo mkdir $path_foleder
                        sudo chmod 777 $path_foleder
                        create_record_in_log $1 $path_foleder 1
                        if [[ $2 = 2 ]]; then
                            count_files=$((1 + $RANDOM % 10))
                        fi
                        generate_files $1 $2
                        count_fi=1
                        count_create_files=0
                        count_create_folders=$(($count_create_folders+1))
                    fi
                fi
            fi
            if [[ $count_create_folders == $count_folder ]]; then
                break 2 
            fi
        done
        count_f=$(($count_f+1))
    done
}

#генерация файлов
function generate_files {
    while [ $count_create_files != $count_files ]
    do
        for (( i=0; $i<${#part_1_len}; i=$(($i+1)) ))
        do
            name_file=""
            for (( j=0; $j<${#part_1_len}; j=$(($j+1)) ))
            do
                if [[ $i = $j ]]; then
                    for (( k=1; $k<$(($count_fi+1)); k=$(($k+1)) ))
                    do
                        name_file+=${part_1_len:$j:1}
                    done
                else
                    name_file+=${part_1_len:$j:1}
                fi
            done
            
            Day="_$(date +%d%m)$(date | awk '{print $NF}' | awk '{print substr($0,3,2)}')"
            name_file+=$Day
            name_file+=".$part_2_len"
            echo $name_file
            path_file=$path$name_folder/$name_file
            # проверка на минимум 4 символа в папке
            if [[ ${#name_file} -le 255 ]]; then
                if [[ ${#name_file} -ge 4 ]]; then
                    #проверка на существование уже этого файла
                    if ! [ -f $path_file ]; then
                        case $2 in
                        1)
                            sizetype="K";;
                        2)
                            sizetype="M";;
                        esac
                        sudo fallocate -l "$size$sizetype" "$path_file"
                        create_record_in_log $1 $path_file 2
                        if [[ $(df / | awk 'NR==2 {print int($4/1024/1024)}') = 0 ]]; then
                            echo "Память закончилась"
                            endTime
                            printTime
                            exit
                        fi
                        count_create_files=$(($count_create_files+1))
                    fi
                fi
            fi
            if [[ $count_create_files == $count_files ]]; then
                break 2 
            fi
        done 
        count_fi=$(($count_fi+1))
    done
}

function create_record_in_log {
    path_log=$1
    path_files_or_folder=$2
    date_create=$(date "+%D %T")
    if [[ $3 = 2 ]]; then
        size_file=$(ls -lh $2 | awk '{print ($5)}')
        echo "$path_files_or_folder $date_create $size_file" >> $path_log
    else
        echo "$path_files_or_folder $date_create" >> $path_log
    fi
}

function create_log_file {
    touch $1
}

function startTime {
    StartTimeH=$(date +"%T")
    StartDateH=$(date | awk '{print $NF}')"-"$(date +%m)"-"$(date +%d)
    start_sub=$(date +%s.%N)
}

function endTime {
    EndTimeH=$(date +"%T")
    EndDateH=$(date | awk '{print $NF}')"-"$(date +%m)"-"$(date +%d)
    end_sub=$(date +%s.%N)
}

function printTime {
    runtime_sub=$( echo "$end_sub - $start_sub" | bc)
    echo "Script start time $StartDateH $StartTimeH"
    echo "Script execution time (in seconds) = ${runtime_sub}"
    echo "Script end time $EndDateH $EndTimeH"
}