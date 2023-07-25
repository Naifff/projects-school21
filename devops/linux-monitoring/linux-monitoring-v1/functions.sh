#!/bin/bash

function set_date {
    sudo timedatectl set-timezone Europe/Moscow
}

function get_color {
    case $2 in
    1) color='\033[37m';;
    2) color='\033[31m';;
    3) color='\033[32m';;
    4) color='\033[34m';;
    5) color='\033[35m';;
    6) color='\033[30m';;
    0) 
        case $1 in
            1) color='\033[37m';;
            2) color='\033[31m';;
        esac;;
    esac
    echo $color
}

function get_bgcolor {
    case $2 in
    1) bgcolor='\033[47m';;
    2) bgcolor='\033[41m';;
    3) bgcolor='\033[42m';;
    4) bgcolor='\033[44m';;
    5) bgcolor='\033[45m';;
    6) bgcolor='\033[40m';;
    0) 
        case $1 in
            1) bgcolor='\033[40m';;
            2) bgcolor='\033[44m';;
        esac;;
    esac
    echo $bgcolor
}

function get_name_color {
    case $1 in
    1) name='white';;
    2) name='red';;
    3) name='green';;
    4) name='blue';;
    5) name='purple';;
    6) name='black';;
    0) 
        case $2 in
            1) 
                case $3 in
                    1) name='white';;
                    2) name='red';;
                esac;;
            2) 
                case $3 in
                    1) name='black';;
                    2) name='blue';;
                esac;;
        esac;;
    esac
    echo " ($name)"
}

function get_names_color {
    echo 
    echo Column 1 background = $( if [[ $1 = 0 ]] ; then echo "default"; else echo $1; fi ) $(get_name_color $1 2 1)
    echo Column 1 font color = $( if [[ $2 = 0 ]] ; then echo "default"; else echo $2; fi ) $(get_name_color $2 1 1)
    echo Column 2 background = $( if [[ $3 = 0 ]] ; then echo "default"; else echo $3; fi ) $(get_name_color $3 2 2)
    echo Column 2 font color = $( if [[ $4 = 0 ]] ; then echo "default"; else echo $4; fi ) $(get_name_color $4 1 2)
}

normal='\033[0m'

function set_parameters {
    parameter=$(cat parameters.conf | grep $1)
    clear=${parameter##*"="}
    if [[ $clear =~ [0-9] ]]; then
        if [[ $clear != [1-6] ]]; then
            echo 0
        fi
    else
        echo 0
    fi
    echo $clear
}

function validated_parameters {
    if [[ $1 =~ [0-9] ]]; then
        if [[ $1 != [1-6] ]]; then
            echo "параметр должен содержать цифры 1-6"
            exit
        fi
    else
        echo "параметр должен содержать цифры"
        exit
    fi
}

function get_info {
    chmod +rx ../mask.txt
    printf "$1$2HOSTNAME$5 = $3$4$(hostname)$5\n"
    printf "$1$2TIMEZONE$5 = $3$4$(timedatectl | grep 'Time zone: ' | sed 's/                Time zone: //')$5\n"
    printf "$1$2USER$5 = $3$4$USER$5\n"
    printf "$1$2OS$5 = $3$4$(hostnamectl | grep 'Operating System: ' | sed 's/Operating System: //')$5\n"
    printf "$1$2DATE$5 = $3$4$(date +"%d %a %y %T")$5\n"
    printf "$1$2UPTIME$5 = $3$4$(uptime -p)$5\n"
    printf "$1$2UPTIME_SEC$5 = $3$4up $(awk '{print $1}' /proc/uptime) sec$5\n"
    printf "$1$2IP$5 = $3$4$(ip a | grep "inet " | sed 's/\/../ /' | sed -n '1'p | awk '{print $2}')$5\n"
    printf "$1$2MASK$5 = $3$4$(grep $(ip a | grep 'inet ' | grep -o '/..' | sed -n '1'p) ../mask.txt | awk '{print $2}')$5\n"
    printf "$1$2GATEWAY$5 = $3$4$(ip r | grep 'default via' | awk '{print $3}')$5\n"
    printf "$1$2RAM_TOTAL$5 = $3$4$(free | grep 'Mem' | awk '{printf "%.3f GB", $2 / 1048576}')$5\n"
    printf "$1$2RAM_USED$5 = $3$4$(free | grep 'Mem' | awk '{printf "%.3f GB", $3 / 1048576}')$5\n"
    printf "$1$2RAM_FREE$5 = $3$4$(free | grep 'Mem' | awk '{printf "%.3f GB", $4 / 1048576}')$5\n"
    printf "$1$2SPACE_ROOT$5 = $3$4$(df | grep '/$' | awk '{printf "%.2f MB", $2 / 1024}')$5\n"
    printf "$1$2SPACE_ROOT_USED$5 = $3$4$(df | grep '/$' | awk '{printf "%.2f MB", $3 / 1024}')$5\n"
    printf "$1$2SPACE_ROOT_FREE$5 = $3$4$(df | grep '/$' | awk '{printf "%.2f MB", $4 / 1024}')$5\n"
}

function save_file {
    echo -n "Сохранить результат в файл? (Y/N)"
    read item
    case "$item" in
        y|Y) 
            get_info >> $(date +"%d_%m_%y_%H_%M_%S").status
        ;;
        *) echo "Прервана обработка";;
    esac
}