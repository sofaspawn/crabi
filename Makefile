main: main.c
	clang main.c -lm -lraylib -Wall -Wextra -Werror && ./a.out
