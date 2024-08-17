CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic
NCURSFLAGS = -lform -lncurses


all: app_test 

app_test: 
		$(CC) -c brick_game/tetris/*.c  gui/cli/*.c  app_test.c
		$(CC) *.o -o app_test
		./app_test
		rm *.o


app_ncurses:
		$(CC) -c brick_game/tetris/*.c  gui/cli/*.c  app_ncurses.c
		$(CC) $(NCURSFLAGS) *.o -o app_test
		./app_test
		rm *.o

clean: 
	rm -rf *.o ./app_test

clang:
	clang-format -i */*/*.c  *.c

rebuild: clean app_ncurses