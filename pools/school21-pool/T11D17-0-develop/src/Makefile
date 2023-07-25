CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURSES=dmanager_module.c door_struct.c
SOURSES2=door_struct.c list.c list_test.c
SOURSES3=stack_test.c stack.c
OBJECTS=$(SOURSES:.c=.o)
OBJECTS2=$(SOURSES2:.c=.o)
OBJECTS3=$(SOURSES3:.c=.o)
EXECUTABLE=../build/Quest_1
EXECUTABLE2=../build/Quest_2
EXECUTABLE3=../build/Quest_3

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

list_test: $(OBJECTS2)

	$(CC) $(OBJECTS2) -o $(EXECUTABLE2)

stack_test: $(OBJECTS3)

	$(CC) $(OBJECTS3) -o $(EXECUTABLE3)