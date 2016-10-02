all: stack_func.o main.o
	gcc -w -o par_stack stack_func.o main.o -Wno-deprecated

main.o: main.c
	gcc -c main.c -Wno-deprecated

my_fun.o: stack_library.h my_fun.c
	gcc -c stack_func.c -Wno-deprecated
clean:
	rm *.o
