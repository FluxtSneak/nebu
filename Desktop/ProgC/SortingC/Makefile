CC = gcc -Wall -Wextra -lm 

all: quicksort.out tri_bulle.out tri_pile.out

quicksort.out: quicksort.o tptableau.o
	$(CC) $^ -o $@

tri_bulle.out: tri_bulle.o tptableau.o
	$(CC) $^ -o $@

tri_pile.out: tri_pile.o tptableau.o librairie_pile.o
	$(CC) $^ -o $@


tri_pile.o: tri_pile.c
	$(CC) $< -c 

librairie_pile.o: librairie_pile.c librairie_pile.h
	$(CC) $< -c 


tri_bulle.o: tri_bulle.c 
	$(CC) $< -c 

quicksort.o: quicksort.c 
	$(CC) $< -c 

tptableau.o: tptableau.c tptableau.h
	$(CC) $< -c

clean: 
	@rm -f *.o *.out

rebuild: clean tri_bulle.out quicksort.out 
