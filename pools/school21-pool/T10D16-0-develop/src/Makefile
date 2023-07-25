CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURSES=s21_string_test.c s21_string.c
SOURSES2=s21_string.c
SOURSES3=s21_string_test.c
OBJECTS=$(SOURSES:.c=.o)
EXECUTABLE=../build/Quest_1
EXECUTABLE2=../build/Quest_2
EXECUTABLE3=../build/Quest_3
EXECUTABLE4=../build/Quest_4
EXECUTABLE5=../build/Quest_5
EXECUTABLE6=../build/Quest_6
EXECUTABLE7=../build/Quest_7

all: $(SOURSES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o

rebuild:
	make clean
	make all

string.bo: $(SOURSES2)
	$(CC) $(CFLAGS) $(SOURSES2)

string_test.strlen: $(SOURSES3)
	$(CC) $(CFLAGS) -DMACROLEN $(SOURSES3)

string_test.strcmp: $(SOURSES3)
	$(CC) $(CFLAGS) -DMACROCMP $(SOURSES3)

string_test.strcpy: $(SOURSES3)
	$(CC) $(CFLAGS) -DMACROCPY $(SOURSES3)

string_test.strcat: $(SOURSES3)
	$(CC) $(CFLAGS) -DMACROCAT $(SOURSES3)

string_test.strchr: $(SOURSES3)
	$(CC) $(CFLAGS) -DMACROCHR $(SOURSES3)

string_test.strstr: $(SOURSES3)
	$(CC) $(CFLAGS) -DMACROSTR $(SOURSES3)

string_test.strtok: $(SOURSES3)
	$(CC) $(CFLAGS) -DMACROTOK $(SOURSES3)

strlen_tests: string.bo string_test.strlen
	$(CC) *.o -o $(EXECUTABLE)
	make clean

strcmp_tests: string.bo string_test.strcmp
	$(CC) *.o -o $(EXECUTABLE2)
	make clean

strcpy_tests: string.bo string_test.strcpy
	$(CC) *.o -o $(EXECUTABLE3)
	make clean

strcat_tests: string.bo string_test.strcat
	$(CC) *.o -o $(EXECUTABLE4)
	make clean

strchr_tests: string.bo string_test.strchr
	$(CC) *.o -o $(EXECUTABLE5)
	make clean

strstr_tests: string.bo string_test.strstr
	$(CC) *.o -o $(EXECUTABLE6)
	make clean

strtok_tests: string.bo string_test.strtok
	$(CC) *.o -o $(EXECUTABLE7)
	make clean
