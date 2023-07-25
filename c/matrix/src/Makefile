CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -std=c11
LDFLAGS = -O2 -Wall -Wextra -Werror -std=c11
SOURCE=$(wildcard m*.c)
OS := $(shell uname)

ifeq ($(OS), Linux)  # Linux
	ADD_LIB = -lcheck -lm -lpthread -lrt -lsubunit
else
	ADD_LIB = -lcheck -lm -lpthread
endif

PROJECTNAME=matrix
TEST_FILE=test.c

all: clean ${PROJECTNAME}.a

${PROJECTNAME}.a:
	${CC} $(CFLAGS) ${ADD_LIB} ${SOURCE}
	ar -cr ${PROJECTNAME}.a *.o
	rm -rf *.o

test: ${TEST_FILE} ${PROJECTNAME}.a
	${CC} ${LDFLAGS} -o $@ $^ -lcheck ${ADD_LIB}
	./$@

gcov_report: clean ${SOURCE} ${TEST_FILE}
	${CC} --coverage ${SOURCE} ${TEST_FILE} $(ADD_LIB) -o gcov
	./gcov
	lcov -t "./gcov" -o ${PROJECTNAME}.info --no-external -c -d .
	genhtml -o report ${PROJECTNAME}.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gcov

check:
ifeq ("","$(wildcard ./.clang-format)")
	cp -f ../materials/linters/.clang-format ./.clang-format
endif
	clang-format -n -style=Google *.c

clean:
	rm -rf *.o *.a test
	rm -rf *.gcno *gcda *.gcov gcov 
	rm -rf report *.info
