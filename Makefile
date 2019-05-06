#Created on 7/5/2019 01:50:00
#Author: Dwaipayan Ray
#make or make all builds the target
#make run executes the target
#make clean removes the target

CC=gcc
CFLAGS=-Wall
DEPS=main.c encrypt.c decrypt.c conv.c
HEADERS=crypt.h conv.h

all: $(DEPS) $(HEADERS)
	$(CC) $(CFLAGS) -o crypt $(DEPS)

run: crypt
	 ./crypt

clean: crypt
	rm -f crypt



