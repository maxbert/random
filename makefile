all: rand.o
	gcc rand.o

rand.o: rand.c
	gcc -c rand.c

clean:
	rm *.o
	rm *~

run: all
	./a.out
