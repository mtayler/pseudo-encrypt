all:
	gcc main.c -oencrypt -lm
debug:
	gcc main.c -oencrypt -lm -g
