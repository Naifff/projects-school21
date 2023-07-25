#!/bin/bash

agents=("Mozilla" "Google Chrome" "Opera" "Safari" "Internet Explorer" "Microsoft Edge" "Crawler and bot" "Library and net tool")
methods=("GET" "POST" "PUT" "PATCH" "DELETE")
response_codes=("200" "201" "400" "401" "403" "404" "500" "501" "502" "503")
urls=(
"https://yandex.ru/"
"https://youtube.com/"
"https://google.com/"
"https://vk.com/"
"https://mail.ru/"
"https://ok.ru/"
"https://avito.ru/"
"https://instagram.com/"
"https://turbopages.org/"
"https://gismeteo.ru/"
"https://wildberries.ru/"
"https://facebook.com/"
"https://wikipedia.org/"
"https://google.ru/"
"https://market.yandex.ru/"
"https://kinopoisk.ru/"
"https://lenta.ru/"
"https://ria.ru/"
"https://gosuslugi.ru/"
"https://ozon.ru/"
"https://rambler.ru/"
"https://rbc.ru/"
"https://news.mail.ru/"
"https://xvideos.com/"
"https://aliexpress.ru/"
"https://drom.ru/"
"https://sberbank.ru/"
"https://twitter.com/"
"https://facebook.net/"
"https://championat.com/"
"https://mk.ru/"
"https://pikabu.ru/"
"https://whatsapp.com/"
"https://novostinedeli24.com/"
)
ext=(
"gif"
"png"
"jpg"
"mp4"
"mp3"
"html"
)

for i in {1..5}
do
  date=$(date +%Y-%m-%d -d "$i day ago")
  filename="$date.log"
  touch $filename

  num_records=$((RANDOM % 901 + 100))

  for (( j=0; j<$num_records; j++ ))
  do
    ip=$((RANDOM % 256)).$((RANDOM % 256)).$((RANDOM % 256)).$((RANDOM % 256))
    method=${methods[$((RANDOM % ${#methods[@]}))]}
    file="/page_$((RANDOM % 10)).${ext[$((RANDOM % ${#ext[@]}))]}"
    response_code=${response_codes[$((RANDOM % ${#response_codes[@]}))]}
    agent=${agents[$((RANDOM % ${#agents[@]}))]}
    url=${urls[$((RANDOM % ${#urls[@]}))]}
    
    curr_timestamp=$(date -u +%s)
    new_timestamp=$(echo "$curr_timestamp - ($i * 24 * 60 * 60)" | bc)
    random_timestamp=$(shuf -i "$new_timestamp-$curr_timestamp" -n 1)
    curr_date=$(date -u -d @$random_timestamp +"%d/%b/%Y:%H:%M:%S %z")

    echo "$ip - - [$curr_date] \"$method $file HTTP/1.1\" $response_code $((RANDOM % 1000)) $url \"$agent\" \"-\"" >> $filename
  done
done