#!/bin/bash/

echo "Введите путь к файлу"

read name

echo "Введите строку, которую хотите заменить"

read line1

echo "Введите строку, на которую хотите заменить"

read line2

if [[ $line1 != "" && $line2 != "" ]]; then 
#под вопросом путь к корневой директории

sed -i.old "s/$line1/$line2/gi" $name
path_file=$name
size_file=$(stat -f %z $name)
data_file=$(date -r $name +'%Y-%m-%d %H:%M')
sha_file=$(shasum -a 256 $name | awk '{ print $1 }')
echo "$path_file - $size_file - $data_file - $sha_file - sha256" >> files.log
else
echo "Все пропало!"
fi

rm $name.old
 
