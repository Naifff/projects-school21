import bs4
import json


class Parser:
    def __init__(self, source):
        self.__dirt = ["января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября",
                       "ноября", "декабря"]
        self.__source = source
        self.__content = self.get_content()
        self.__json = json
        self.__path = ""
        self.__list = []

    def parse(self):
        soup = bs4.BeautifulSoup(self.__content, 'html.parser')
        table = soup.find_all("tbody")[-1]
        tr = table.tr
        while tr.find_next_sibling("tr"):
            self.__list.append({
                "date": self.get_date(tr.find_all("td")[0].text),
                "max_temp": float(tr.find_all("td")[1].text),
                "min_temp": float(tr.find_all("td")[2].text),
                "arf_temp": float(tr.find_all("td")[3].text),
                "atmospher": float(tr.find_all("td")[4].text),
                "speed": int(tr.find_all("td")[5].text),
                "fallout": int(tr.find_all("td")[6].text),
                "eff_temp": float(tr.find_all("td")[7].text)
            })
            tr = tr.find_next_sibling("tr")
        return self.__list

    def get_date(self, date):
        cnt = 0
        for f_date in self.__dirt:
            cnt += 1
            date = date.replace(f" {f_date}", f"-{cnt}")
        return date

    def save(self, source):
        result = self.__list
        if len(result) == 0:
            result = self.parse()
        self.__json = json.dumps(result, indent=4, ensure_ascii=False)
        self.__path = source
        with open(self.__path, "w+") as f:
            f.write(self.__json)

    def get_content(self):
        with open(self.__source) as f:
            return f.read()
