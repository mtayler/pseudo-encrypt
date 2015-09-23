all:
	gcc main.c -oencrypt -lm
debug:
	gcc main.c -oencrypt -lm -g

clean:
	-rm -f decrypted.txt encrypted.vir
	-rm -rf *.dSYM
