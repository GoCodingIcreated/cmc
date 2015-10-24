all: genrand
genrand:rand.c rand.h main.c
	gcc -std=gnu99 -Wall -Werror main.c rand.c -o genrand
clean:
	rm -rf *.o
	rm -rf genrand
