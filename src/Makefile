CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic


all: app_test clean clang

app_test: 
		$(CC) $(CFLAGS) -c brick_game/tetris/*.c 
		$(CC) *.o -o app_test
		./app

clean: 
	rm -rf *.o ./app

clang:
	clang-format -i */*/*.c  