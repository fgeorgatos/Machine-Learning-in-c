NB_recommended: main.o parse.o recommend.o
	gcc -o NB_recommended main.o parse.o recommend.o -lm -Wall
main.o: main.c 
	gcc -c main.c -lm -Wall
parse.o: parse.c
	gcc -c parse.c -lm -Wall
recommend.o: recommend.c
	gcc -c recommend.c -lm -Wall
clean :
	rm -rf*.o NB_recommended
