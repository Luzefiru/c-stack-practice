# change implementations here by editing the IMPLEMENTATION variable
# available options: array | list
IMPLEMENTATION := array

start:
	make clean && make all && ./main.exe

all: main

main: main.o stack.o
	gcc -o main main.o stack.o

main.o:
	gcc -c ./src/main.c

stack.o:
	gcc -c ./src/stack/$(IMPLEMENTATION)/stack.c

clean:
	rm -fr main.* stack.*