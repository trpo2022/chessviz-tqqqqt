
output: main.o
	gcc main.o -o output

main.o: main.c
	gcc -c -Wall -Werror main.c

clean:
	rm *.o output
