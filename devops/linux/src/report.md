## №1. Установка ОС

1. Узнать версию Ubuntu, выполнив команду

```
cat /etc/issue
```

2. 

![img](assets/1.png)

## №2. Создание пользователя

1. Вставьте скриншот вызова команды для создания пользователя.

![img](assets/2.1.png)

2. Новый пользователь должен быть в выводе команды

```
cat /etc/passwd
```

![img](assets/2.2.png)

## №3. Настройка сети ОС

1. Задать название машины вида user-1

![img](assets/3.1.png)

* Чтобы изменить название машины были выполненые следующие команды:
```sudo vim /etc/hostname```
```reboot```

![img](assets/3.2.png)

2. Установить временную зону, соответствующую вашему текущему местоположению

![img](assets/3.3.png)

3. Вывести названия сетевых интерфейсов с помощью консольной команды
```ifconfig -a```

![img](assets/3.4.png)

* Перед этим установить пакет для вывода сетевых адаптеров

  ```sudo apt install net-tools```

* lo или local loopback (локальная петля). Служит для подключения по сети к этому же компьютеру и не требует дополнительной настройки;

4. Используя консольную команду получить ip адрес устройства, на котором вы работаете, от DHCP сервера.

![img](assets/3.5.png)

* Dynamic Host Configuration Protocol (DHCP) — автоматический предоставляет IP адреса и прочие настройки сети (маску сети, шлюз и т.п) компьютерам и различным устройствам в сети.

5. Определить и вывести на экран внешний ip-адрес шлюза (ip) и внутренний IP-адрес шлюза, он же ip-адрес по умолчанию (gw).

* внешний ip-адрес шлюза (ip):

![img](assets/3.6.png)

* внутренний IP-адрес шлюза:

  ![img](assets/3.7.png)

6. Задать статичные (заданные вручную, а не полученные от DHCP сервера) настройки ip, gw, dns (использовать публичный DNS серверы, например 1.1.1.1 или 8.8.8.8).

```vim /etc/netplan/00-installer-config.yaml```

* Открываем файл

  ![img](assets/3.8.png)

* Задаем вручную статичные настройки ip, gw, dns, полученные от DHCP сервера

  ![img](assets/3.9.png)

  ![img](assets/3.10.png)

  ![img](assets/3.11.png)

## №4.  Обновление ОС

1. Обновить системные пакеты до последней на момент выполнения задания версии

![img](assets/4.png)

## №5. Использование команды sudo

1. Разрешить пользователю, созданному в Part 2, выполнять команду sudo.

![img](assets/5.png)

Sudo — это утилита, предоставляющая привилегии root для выполнения административных операций в соответствии со своими настройками. Она позволяет легко контролировать доступ к важным приложениям в системе. По умолчанию, при установке Ubuntu первому пользователю (тому, который создаётся во время установки) предоставляются полные права на использование sudo. Т.е. фактически первый пользователь обладает той же свободой действий, что и root.

## №6. Установка и настройка службы времени

1. Настроить службу автоматической синхронизации времени. Вывод следующей команды

```timedatectl show```

должен содержать: NTPSynchronized=yes

![img](assets/6.png)

## №7. Установка и использование текстовых редакторов
1. Установить текстовые редакторы VIM (+ любые два по желанию NANO, MCEDIT, JOE и т.д.)

```sudo apt install vim``` 
```sudo apt install nano``` 
```sudo apt install mcedit```

2. Используя каждый из трех выбранных редакторов, создайте файл test_X.txt, где X -- название редактора, в котором создан файл. Напишите в нём свой никнейм, закройте файл с сохранением изменений.
3. Используя каждый из трех выбранных редакторов, откройте файл на редактирование, отредактируйте файл, заменив никнейм на строку "21 School 21", закройте файл без сохранения изменений.
4. Используя каждый из трех выбранных редакторов, отредактируйте файл ещё раз (по аналогии с предыдущим пунктом), а затем освойте функции поиска по содержимому файла (слово) и замены слова на любое другое.
### VIM
1. 

![img](assets/7.1.png)

2. 

![img](assets/7.2.png)

3. 

![img](assets/7.3.png) 

![img](assets/7.4.png)

4. 

![img](assets/7.5.png) 

![img](assets/7.6.png)

5. 

![img](assets/7.7.png)

![img](assets/7.8.png)

* vim test_VIM.txt
* Режим редактирования: I
* Выйти из режима редактирования: esc
* Выход с охранением: :wq  
* Выход без сохранения: :q  
* Поиск: /<текст, который хотим найти> 
* Замена: :s/<что хотим изменить>/<на что хотим заменить>
### MCEDIT
1. 

![img](assets/7.9.png)

2. 

![img](assets/7.10.png)

![img](assets/7.11.png)

![img](assets/7.12.png)

3. 

![img](assets/7.13.png)

![img](assets/7.14.png)

![img](assets/7.12.png)

4. 

![img](assets/7.15.png)

![img](assets/7.16.png)

5. 

![img](assets/7.17.png)

![img](assets/7.18.png)

* mcedit test_mcedit.txt 
* Выход с охранением: F2 (yes) + F10
* Выход без сохранения: F10(no)  
* Поиск: F7 + <текст который ищем> + <ок>  
* Замена: F4 + <что хотим изменить> + <на что хотим заменить> + replace
### NANO
1. 

![img](assets/7.19.png)  

2. 

![img](assets/7.20.png)

3. 

![img](assets/7.21.png)

4. 

![img](assets/7.22.png)

5. 

![img](assets/7.23.png)

![img](assets/7.24.png)

* nano test_NANO.txt 
* Выход с охранением: CTRL + x, затем y  b enter
* Выход без сохранения: CTRL + x, затем n 
* Поиск: CTRL + W, затем enter (alt + w для перехода к след. вхождению, ctrl + c  для преращения поиска)
* Замена: CTRL + \+ <что хотим изменить + enter> + <на что хотим заменить + enter> + A(для замены все вхождения) или y и n по отдельности

## №8. Установка и базовая настройка сервиса SSHD
1. Установить службу SSHd.
* sudo apt-get install ssh
* sudo apt install openssh-server

![img](assets/8.1.png)

2. Добавить автостарт службы при загрузке системы.
* sudo systemctl enable ssh
* systemctl status ssh

![img](assets/8.2.png)

3. Перенастроить службу SSHd на порт 2022.
* sudo vim /etc/ssh/sshd_config

![img](assets/8.3.png)

* systemctl restart sshd
4. Используя команду ps, показать наличие процесса sshd. Для этого к команде нужно подобрать ключи.
* ps (показывает запущенные процессы, выполняемые пользователем в окне терминала);
* ps -e или ps -A (Чтобы просмотреть все запущенные процессы);
* ps -d (Чтобы показать все процессы, кроме лидеров сессии);
* ps -d -N (можно инвертировать вывод с помощью переключателя -N. Например, если хочу вывести только лидеров сеансов)
* ps T (увидеть только процессы, связанные с этим терминалом);
* ps r (просмотреть все работающие (running) процессы);
* ps -p 'pid' (если вы знаете идентификатор процесса PID, вы можете просто использовать следующую команду, для вывода процесса с этим 'pid');
* ps -p 'pid1' 'pid2'
* ps U 'userlist' (найти все процессы, выполняемые конкретным пользователем);
* ps -ef (получить полный список);

![img](assets/8.5.png)

5. Перезагрузить систему
### NETSTAT

![img](assets/8.4.png)

* -t (--tcp) отображает соедниеня только по tcp
* -a (--all) вывод всех активных подключений TCP 
* -n (--numeric) вывод активных подключений TCP с отображением адресов и номеров портов в числовом формате
* Proto: Название протокола (протокол TCP или протокол UDP);
* recv-Q: очередь получения сети
* send-Q: Сетевая очередь отправки
* Local Address адрес локального компьтера и используемы номер порта
* Foreign Address адрес и номер удаленного компьтера к которомц подключен сокет
* State состояние сокетв
* 0.0.0.0 означает IP-адрес на локальной машине

## №9. Установка и использование утилит top, htop
1. По выводу команды top определить и написать в отчёте:

![img](assets/9.1.png)

* uptime - 2min;
* количество авторизованных пользователей - 1;
* общую загрузку системы - 0.00, 0.01, 0.00
* общее количество процессов - 127;
* загрузку cpu - 0.0%;
* загрузку памяти - 238.1/7759.6;
* pid процесса занимающего больше всего памяти - 725|696 (top -o %MEM);

![img](assets/9.2.png)

* pid процесса, занимающего больше всего процессорного времени - 1287 (top -o %CPU);

![img](assets/9.3.png)

2. В отчёт вставить скрин с выводом команды htop:
* отсортированному по PID, PERCENT_CPU, PERCENT_MEM, TIME

![img](assets/9.4.png)

![img](assets/9.5.png)

![img](assets/9.6.png)

![img](assets/9.7.png)

* отфильтрованному для процесса sshd

![img](assets/9.8.png)

* с процессом syslog, найденным, используя поиск

![img](assets/9.9.png)

* с добавленным выводом hostname, clock и uptime

![img](assets/9.10.png)

## №10. Использование утилиты fdisk
1. Запустить команду fdisk -l.

![img](assets/10.1.png)

* название жесткого диска - vbox HARDDISK;
* размер - 11.5GiB;
* количество секторов - 24109056;
* размер swap - 0GiB.

![img](assets/10.2.png)

## №11. Использование утилиты df
1. Запустить команду df.
В отчёте написать для корневого раздела (/):
* размер раздела - 11758760;
* размер занятого пространства - 3129304;
* размер свободного пространства - 8010348;
* процент использования - 29%;
Определить и написать в отчёт единицу измерения в выводе - килобайт
2. Запустить команду df -Th.
В отчёте написать для корневого раздела (/):
* размер раздела - 12G;
* размер занятого пространства - 3G;
* размер свободного пространства - 7.7G;
* процент использования  - 29%
Определить и написать в отчёт тип файловой системы для раздела - ext4.

![img](assets/11.png)

## №12. Использование утилиты du
1. Запустить команду du.
2. Вывести размер папок /home, /var, /var/log (в байтах)

![img](assets/12.1.png)

3. Вывести размер папок /home, /var, /var/log (в человекочитаемом виде)

![img](assets/12.2.png)

4. Вывести размер всего содержимого в /var/log (не общее, а каждого вложенного элемента, используя *)

![img](assets/12.3.png)

## №13. Установка и использование утилиты ncdu
1. Установить утилиту ncdu. 
```sudo apt-get install ncdu```
2. Вывести размер папок /home, /var, /var/log.

![img](assets/13.1.png)

![img](assets/13.2.png)

![img](assets/13.3.png)

## №14. Работа с системными журналами
sudo vim /var/log/dmesg  
sudo vim /var/log/syslog 
sudo vim /var/log/auth.log 
1. Написать в отчёте время последней успешной авторизации, имя пользователя и метод входа в систему

![img](assets/14.1.png)

2. Перезапустить службу SSHd. 
sudo systemctl restart ssh
3. Вставить в отчёт скрин с сообщением о рестарте службы (искать в логах).

![img](assets/14.2.png)

## №15. Использование планировщика заданий CRON
1. Используя планировщик заданий, запустите команду uptime через каждые 2 минуты.

![img](assets/15.1.png)

* Найти в системных журналах строчки (минимум две в заданном временном диапазоне) о выполнении.

![img](assets/15.2.png)

* Вывести на экран список текущих заданий для CRON.
* Вставить в отчёт скрины со строчками о выполнении и списком текущих задач
2. Удалите все задания из планировщика заданий.
* В отчёт вставьте скрин со списком текущих заданий для CRON.

![img](assets/15.3.png)