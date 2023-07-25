FLAGS = -std=c11 -Wall -Werror -Wextra
CHFLAGS = -lcheck -lm -lpthread

all: clean s21_decimal.a test

test: s21_decimal.a
	gcc test.c s21_decimal.a -o test.out $(CHFLAGS)
	./test.out

s21_decimal.a: s21_decimal.o
	ar -cr s21_decimal.a *.o

s21_decimal.o:
	gcc $(FLAGS) -c s21_*.c

clean:
	rm -rf  *.a *.o *.out *.txt *.info *.gcno *.gcda report *.cfg

gcov_report:
	gcc --coverage -lcheck test.c s21_*.c -o test.out
	./test.out
	lcov -t "test.out" -o test.info --no-external -c -d .
	genhtml -o report test.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gcov

