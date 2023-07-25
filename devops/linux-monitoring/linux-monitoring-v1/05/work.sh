#!/bin/bash
echo "Total number of folders (including all nested ones) = $(find $1* 2>/dev/null -type d | wc -l)"
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
for (( i=1; i < 6; i++ ))
do 
    echo $(find $1* -type d -exec du -ch {} + 2>/dev/null | grep -v total| sort -hr | cat -n | sed -n "${i}p" | awk '{print $1, "- "$3"/,", $2}')
done
echo etc up to $(ps -p $$ -o etimes | sed -n "2p")
echo "Total number of files = $(find $1* -type f 2>/dev/null | wc -l)"
echo Number of:  
echo "Configuration files (with the .conf extension) = $(find $1* -type f 2>/dev/null -iname "*.conf" | wc -l)"
echo Text files = $(find $1* -type f 2>/dev/null -iname "*.txt" | wc -l)
echo Executable files = $(find $1* -type f 2>/dev/null -executable | wc -l)
echo "Log files (with the extension .log) = $(find $1* -type f 2>/dev/null -iname "*.log" | wc -l)"
echo Archive files = $(find $1* -type f 2>/dev/null -name "*.zip" -o -name "*.7z" -o -name "*.rar" -o -name "*.tar" | wc -l)  
echo Symbolic links = $(find $1* -type l 2>/dev/null -iname | wc -l)
echo "TOP 10 files of maximum size arranged in descending order (path, size and type): " 
for (( i=1; i < 11; i++ ))
do 
    echo $(find $1* -type f -exec du -h {} + 2>/dev/null | sort -hr | cat -n | sed -n "${i}p")" $(awk '{print $3}' tmp | awk -F"." '{print $NF}')">tmp
    echo $(awk '{print $1, "- "$3"/,", $2",", $4}' tmp)
done
echo etc up to $(ps -p $$ -o etimes | sed -n "2p")
echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file)"
for (( i=1; i < 11; i++ ))
do 
    echo $(find $1* -type f -exec du -h {} + 2>/dev/null | sort -hr | cat -n | sed -n "${i}p")" $(shasum -a 1 $(awk '{print $3}' tmp))">tmp
    echo $(awk '{print $1, "- "$3"/,", $2",", $4}' tmp)
done
echo etc up to $(ps -p $$ -o etimes | sed -n "2p")
rm -rf tmp