import json
from datetime import datetime


def get_date(date):
    return datetime.strptime(date, "%d-%m")


class Data:
    def __init__(self, source):
        self.__source = source
        self.__file_content = ""
        self.__obj = []

    def parse_json(self):
        self.__obj = json.loads(self.__file_content)

    def get_info_by_day(self, day, month):
        try:
            f_date = datetime(1900, day, month)
            for child_obj in self.__obj:
                if get_date(child_obj["date"]) == f_date:
                    return child_obj
        except Exception as e:
            if e:
                pass

    def get_arf_temp_by_month(self, key, month):
        day_by_month = 0
        summ = 0
        for i in range(1, 31):
            result = self.get_info_by_day(i, month)
            if result is not None:
                day_by_month += 1
                summ += result[key]
        return summ / day_by_month

    def load_file(self):
        with open(self.__source) as f:
            self.__file_content = f.read()
