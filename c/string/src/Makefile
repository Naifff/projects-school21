FLAGS = -std=c11 -Wall -Werror -Wextra #-fsanitize=address -g
TEST_LIBS = -lcheck -lm -lpthread
OS := $(shell uname)

ifeq ($(OS),Linux)
	CHFLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	CHFLAGS = -lcheck -lm -lpthread
endif


all: clean s21_string.a

s21_string.o:
	gcc $(FLAGS) -c s21_*.c

s21_string.a: s21_string.o
	ar -cr s21_string.a *.o
	rm -rf *.o

unit-test.o:
	gcc $(FLAGS) -c unit_test.c s21_*.c

test: unit_test.c s21_string.a
	gcc $(FLAGS)  -fsanitize=address -g unit_test.c $(CHFLAGS) s21_string.a -o unit-test 
#gcc $(FLAGS) unit_test.c $(CHFLAGS) s21_string.a -o unit-test
#-pedantic

gcov_report: s21_string.a
	gcc --coverage s21_*.c unit_test.c $(CHFLAGS) -o gcov
	./gcov
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gcov


clean:
	rm -rf *.o *.a unit-test
	rm -rf *.gcno *gcda *.gcov gcov program
	rm -rf report report.info