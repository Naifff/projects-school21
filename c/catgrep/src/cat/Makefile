CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -D_GNU_SOURCE
SOURCE_TEST=test_cat/test_1_cat.txt test_cat/test_2_cat.txt test_cat/test_3_cat.txt test_cat/test_4_cat.txt test_cat/test_5_cat.txt test_cat/test_case_cat.txt test_cat/s21_cat

all: s21_cat

s21_cat: s21_cat.c
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat

test: s21_cat
	bash test.sh
	rm -rf log.txt

check: s21_cat
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	clang-format -n *.c *.h
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt s21_cat

clean:
	rm -rf test_cat/s21_cat test_cat/*.log s21_cat.d* s21_cat RESULT_VALGRIND.txt

rebuild: 
	clean all
