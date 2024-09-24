#-----------------------------------------------------------------#
#					Makefile for UNIX Systems | WSL | Ubuntu Version
#										using a GNU C Compiler
#-----------------------------------------------------------------#

CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi -std=c11

#
# Compiler flags:
#				-g			-- Enable debugging
#				-Wall		-- Turn on all arnings (not used since it gives aways the bug in this program)
#				-D__USE_FIXED_PROTOTYPES__
#								-- Force the compiler to use the correct headers
#				-amso		-- Dont use GNU extensions. Stick to ANSI C.
# A bit of docker image without stages lol

all: hist

hist: hist.o ./bin/ia.o
	cp ./hist.o ./bin/; rm ./hist.o;
	$(CC) $(CFLAGS) -o ./bin/hist ./bin/hist.o ./bin/ia.o;
	cp ./bin/hist ./app; rm ./bin/hist;

hist.o: hist.c ./bin/ia.h
./bin/ia.o: ./bin/ia.c ./bin/ia.h

clean:
	rm -f ./*/*.o ./app/hist 