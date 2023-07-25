C=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURSES=print_module.c
SOURSES2=main_module_entry_point.c 
SOURSES3=documentation_module.c
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

print: $(SOURSES)
	$(CC) $(CFLAGS) $(SOURSES)

main: $(SOURSES2)
	$(CC) $(CFLAGS) -DMACROQ1 $(SOURSES2)

docs: $(SOURSES3)
	$(CC) $(CFLAGS) $(SOURSES3)

print_module: print main
	$(CC) *.o -o $(EXECUTABLE)
	make clean

documentation_module: print main
	$(CC) *.o -o $(EXECUTABLE2)
	make clean