import requests


class Downloader:
    def __init__(self, url, params):
        self.__url = url
        self.__params = params
        self.__content = ""
        self.__path = ""

    def get_html(self):
        result = ""
        if self.__content == "":
            url = self.forming_url()
            response = requests.get(url)
            response.encoding = "utf-8"
            if response.status_code == 200:
                result = self.__content = response.text
            elif response.status_code == 404:
                result = "Not Found."
        else:
            result = self.__content
        return result

    def save(self, file_path):
        result = self.__content
        if result == "":
            result = self.get_html()
        if result != "Not Found":
            self.__path = file_path
            with open(self.__path, "w+") as f:
                f.write(result)
        else:
            print("Not Found")

    # http://www.hmn.ru/index.php?index=8&value=22113&tz=3&start=2022-11-20&fin=2022-11-28&x=10&y=5
    def forming_url(self):
        url = self.__url + "?"
        for key, value in self.__params.items():
            if key != "y":
                url += f"{key}={str(value)}&"
            else:
                url += f"{key}={str(value)}"
        return url
