from __init__ import process

URL = "http://pogoda-service.ru/climate_table.php"
FILE_PATH = "weather.html"
PARSED_FILE_PATH = "weather.json"

print(process(URL, FILE_PATH, PARSED_FILE_PATH))
