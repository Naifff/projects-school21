CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -std=c11
LDFLAGS = -O2 -Wall -Wextra -Werror -std=c11
Vgrind= CK_FORK=no valgrind --vgdb=no\
--leak-check=full --show-leak-kinds=all\
--trace-children=yes --track-origins=yes\
-v --verbose -q --quiet -s

OS = $(shell uname)
ifeq ($(OS), Linux)
	ADD_LIB = -lpthread -lcheck -pthread -lrt -lm -lsubunit
else
	ADD_LIB = -lcheck -lm -lpthread
endif

SOURCE=3DViewer/parser/s21_parser_file.c 3DViewer/transform/s21_affine_transform.c

TEST_FILE=test/*.c

PROJECTNAME=3DViewer

RM=rm -rf

all: install open
	@echo Executing 'all' complete!

install: clean
	cd 3DViewer && qmake && make && make clean && rm Makefile && cd ../ 

uninstall: clean
	rm -rf 3DViewer/3DViewer

${PROJECTNAME}.a:
	${CC} $(CFLAGS) ${ADD_LIB} ${SOURCE}
	ar -cr ${PROJECTNAME}.a *.o
	$(RM) *.o

test: clean ${TEST_FILE} ${PROJECTNAME}.a
	${CC} ${LDFLAGS} -o tests ${TEST_FILE} ${PROJECTNAME}.a ${ADD_LIB} 
	./tests

gcov_report: clean ${SOURCE} ${TEST_FILE}
	${CC} --coverage ${SOURCE} ${TEST_FILE} $(ADD_LIB) -o gcov
	./gcov
	lcov -t "./gcov" -o ${PROJECTNAME}.info --no-external -c -d .
	genhtml -o report ${PROJECTNAME}.info
	open ./report/index.html
	$(RM) *.gcno *gcda *.gcov

check:
	clang-format -i --style=Google test/*.c 3DViewer/parser/*.c 3DViewer/parser/*.h 3DViewer/transform/*.c 3DViewer/transform/*.h 3DViewer/*.h 3DViewer/*.cpp
	clang-format -n --style=Google test/*.c 3DViewer/parser/*.c 3DViewer/parser/*.h 3DViewer/transform/*.c 3DViewer/transform/*.h 3DViewer/*.h 3DViewer/*.cpp

dvi:
	open dvi.md

dist:
	$(RM) Archive_3DViewer_v1_0/
	mkdir Archive_3DViewer_v1_0
	mkdir Archive_3DViewer_v1_0/src
	cp -r ./3DViewer/3DViewer.app Archive_3DViewer_v1_0/src
	tar cvzf Archive_3DViewer_v1_0.tgz Archive_3DViewer_v1_0/
	$(RM) Archive_3DViewer_v1_0/

open:
	open 3DViewer/3DViewer.app

clean:
	$(RM) *.gcno *gcda *.gcov *.info
	$(RM) report gcov tests
	$(RM) 3DViewer.a
	$(RM) 3DViewer/*.o 3DViewer/.qmake.stash 3DViewer/3DViewer.app
	$(RM) Archive_3DViewer_v1_0.tgz
	@echo Cleanup complete!

.PHONY: clean check
