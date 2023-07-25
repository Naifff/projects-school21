CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURSES=state_sort.c binary_func.c
SOURSES2=state_search.c binary_func.c
SOURSES3=
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

state_sort.oc: $(SOURSES)
	$(CC) $(CFLAGS) $(SOURSES)

state_search.oc: $(SOURSES2)
	$(CC) $(CFLAGS) $(SOURSES2)

state_sort: state_sort.oc
	$(CC) *.o -o $(EXECUTABLE)
	make clean

state_search: state_search.oc
	$(CC) *.o -o $(EXECUTABLE2)
	make clean

clear_state: state_sort.oc
	$(CC) *.o -o $(EXECUTABLE3)
	make clean