CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic


all: app_test 

app_test: 
		$(CC) -c brick_game/tetris/*.c  gui/cli/*.c  app_test.c
		$(CC) *.o -o app_test
		./app_test
		rm *.o

clean: 
	rm -rf *.o ./app_test

clang:
	clang-format -i */*/*.c  

rebuild: clean app_test