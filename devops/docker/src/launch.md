# Предустановка

## Установка Docker на локальную машину

Пакет установки Docker, доступный в официальном репозитории Ubuntu, может содержать не самую последнюю версию. Чтобы точно использовать самую актуальную версию, мы будем устанавливать Docker из официального репозитория Docker. Для этого мы добавим новый источник пакета, ключ GPG от Docker, чтобы гарантировать загрузку рабочих файлов, а затем установим пакет.

Первым делом обновите существующий список пакетов:

```
sudo apt update
```

Затем установите несколько необходимых пакетов, которые позволяют apt использовать пакеты через HTTPS:
```
sudo apt install apt-transport-https ca-certificates curl software-properties-common
```

Добавьте ключ GPG для официального репозитория Docker в вашу систему:

```
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
```

Добавьте репозиторий Docker в источники APT:

```
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu focal stable"
```

Потом обновите базу данных пакетов и добавьте в нее пакеты Docker из недавно добавленного репозитория:

```
sudo apt update
```

Убедитесь, что установка будет выполняться из репозитория Docker, а не из репозитория Ubuntu по умолчанию:

```
apt-cache policy docker-ce
```

Вы должны получить следующий вывод, хотя номер версии Docker может отличаться:

```
Output of apt-cache policy docker-ce
docker-ce:
  Installed: (none)
  Candidate: 5:19.03.9~3-0~ubuntu-focal
  Version table:
     5:19.03.9~3-0~ubuntu-focal 500
        500 https://download.docker.com/linux/ubuntu focal/stable amd64 Packages
```

Обратите внимание, что docker-ce не установлен, но является кандидатом на установку из репозитория Docker для Ubuntu 20.04 (версия focal).

Установите Docker:

```
sudo apt install docker-ce
```

Docker должен быть установлен, демон-процесс запущен, а для процесса активирован запуск при загрузке. Проверьте, что он запущен:

```
sudo systemctl status docker
```

Вывод должен выглядеть примерно следующим образом, указывая, что служба активна и запущена:

```
Output
● docker.service - Docker Application Container Engine
     Loaded: loaded (/lib/systemd/system/docker.service; enabled; vendor preset: enabled)
     Active: active (running) since Tue 2020-05-19 17:00:41 UTC; 17s ago
TriggeredBy: ● docker.socket
       Docs: https://docs.docker.com
   Main PID: 24321 (dockerd)
      Tasks: 8
     Memory: 46.4M
     CGroup: /system.slice/docker.service
             └─24321 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
```

После установки Docker у вас будет доступ не только к службе Docker (демон-процесс), но и к утилите командной строки docker или клиенту Docker. 

## Настройка команды Docker без sudo

По умолчанию команда docker может быть запущена только пользователем root или пользователем из группы docker, которая автоматически создается при установке Docker. Если вы попытаетесь запустить команду docker без префикса sudo или с помощью пользователя, который не находится в группе docker, то получите следующий вывод:

```
Output
docker: Cannot connect to the Docker daemon. Is the docker daemon running on this host?.
See 'docker run --help'.
```

Если вы не хотите каждый раз вводить sudo при запуске команды docker, добавьте свое имя пользователя в группу docker:

```
sudo usermod -aG docker ${USER}
```

Чтобы применить добавление нового члена группы, выйдите и войдите на сервер или введите следующее:

```
su - ${USER}
```

Вы должны будете ввести пароль вашего пользователя, чтобы продолжить.

Проверьте, что ваш пользователь добавлен в группу docker, введя следующее:

```
id -nG
```

```
Output
sammy sudo docker
```

Если вам нужно добавить пользователя в группу docker, для которой вы не выполнили вход, объявите имя пользователя явно, используя следующую команду:

```
sudo usermod -aG docker username
```

В дальнейшем будет подразумеваться, что вы запускаете команду docker от имени пользователя в группе docker. В обратном случае вам необходимо добавлять к командам префикс sudo.
