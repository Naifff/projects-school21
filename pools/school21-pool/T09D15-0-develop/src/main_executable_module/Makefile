CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURSES=main_executable_module.c ../data_libs/data_io.c ../data_module/data_process.c ../data_libs/data_stat.c ../yet_another_decision_module/decision.c
OBJECTS=$(SOURSES:.c=.o)
EXECUTABLE=../../build/Quest_3
SOURSES2=main_executable_module.c data_stat.a ../data_libs/data_io.c ../data_module/data_process.c ../yet_another_decision_module/decision.c
EXECUTABLE2=../../build/Quest_5
OBJECTS2=$(SOURSES2:.c=.o)
DINLIBFLAGS=-c -fPIC
SOURSES3=main_executable_module.c libdata_process.so ../data_libs/data_io.c ../data_libs/data_stat.c ../yet_another_decision_module/decision.c
EXECUTABLE3=../../build/Quest_6
OBJECTS3=$(SOURSES3:.c=.o)
LDDINAMICFLAGS=-ldl -o run -L. -Wl,-rpath,.

all: $(SOURSES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o ../data_libs/*.o ../data_module/*.o ../yet_another_decision_module/*.o

rebuild:
	make clean
	make all

data_stat.a:
	$(CC) $(CFLAGS) ../data_libs/data_stat.c
	ar rc data_stat.a data_stat.o
	rm -rf *.o

build_with_static: $(SOURSES2) $(EXECUTABLE2)

$(EXECUTABLE2): $(OBJECTS2)
	$(CC) $(LDFLAGS) $(OBJECTS2) -o $@
	make clean

data_process.so:
	$(CC) $(DINFLAGS) $(CFLAGS) ../data_module/data_process.c ../data_libs/data_stat.c
	gcc -shared -o /Users/aqualadt/T09D15-0/src/main_executable_module/libdata_process.so data_process.o data_stat.o
	rm -rf *.o

build_with_dynamic: $(SOURSES3) $(EXECUTABLE3)

$(EXECUTABLE3): $(OBJECTS3)
	$(CC) $(LDDINAMICFLAGS) $(OBJECTS3) -o $@
	make clean

