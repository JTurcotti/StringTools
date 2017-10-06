all: jtstring.o main.o
	gcc -o StringTools jtstring.o main.o

jtstring.o: jtstring.c jtstring.h
	gcc -c jtstring.c

main.o: main.c jtstring.h
	gcc -c main.c

run: all
	./StringTools

clean:
	rm *.o
	rm a.*

