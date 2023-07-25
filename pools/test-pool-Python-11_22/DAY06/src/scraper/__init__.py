from download import Downloader
from parse import Parser
from data import Data

# http://pogoda-service.ru/climate_table.php?country=RS&station=275950&
# day_begin=01&month_begin=01&day_end=31&month_end=12
PARAMS = {  # параметры для парсинга страницы выше
    "country": "RS",
    "station": 275950,
    "day_begin": "01",
    "month_begin": "01",
    "day_end": "31",
    "month_end": "12",
}


def process(url, web_page_path=None, data_path=None):
    downloader = Downloader(url=url, params=PARAMS)
    downloader.save(web_page_path)

    parser = Parser(web_page_path)  # в конструкторе он принимает путь к файлу, сохраненному Downloader'ом
    parser.save(data_path)  # сохраняет данные в виде json- или yaml-файла

    f_data = Data(data_path)
    f_data.load_file()
    f_data.parse_json()

    return f_data.get_arf_temp_by_month("max_temp", 1)
