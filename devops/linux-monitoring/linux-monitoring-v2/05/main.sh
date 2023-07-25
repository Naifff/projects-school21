#!/bin/bash

if [[ $# -ne 1 ]]; then
  echo "Usage: $0 <1|2|3|4>"
  exit 1
fi

case $1 in
  1)
    awk '{print $0} END {print "Ip DateTime Method_Url"}'  ../04/*.log | sort -k 9 ;;
  2)
    awk '{print $1}' ../04/*.log | sort | uniq;;
  3)
    awk '$9 ~ /^4|^5/ {print $0}' ../04/*.log;;
  4)
    awk '$9 ~ /^4|^5/ {print $1}' ../04/*.log | sort | uniq;;
  *)
    echo "Invalid parameter. Usage: $0 <1|2|3|4>"
    exit 1;;
esac