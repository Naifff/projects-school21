CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURSES=cipher.c
SOURSES2=logger.c
SOURSES3=
OBJECTS=$(SOURSES:.c=.o)
OBJECTS2=$(SOURSES2:.c=.o)
OBJECTS3=$(SOURSES3:.c=.o)
EXECUTABLE=../build/cipher
EXECUTABLE2=../build/logging_cipher
EXECUTABLE3=../build/

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

cipher.oc: $(SOURSES)
	$(CC) $(CFLAGS) $(SOURSES)

cipher.log: $(SOURSES)
	$(CC) $(CFLAGS) -DMACROQ5 $(SOURSES)

logger.oc: $(SOURSES2)
	$(CC) $(CFLAGS) $(SOURSES2)

cipher: cipher.oc
	$(CC) *.o -o $(EXECUTABLE)
	make clean

logging_cipher: cipher.log logger.oc
	$(CC) *.o -o $(EXECUTABLE2)
	make clean