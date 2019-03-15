CC = gcc

CFlAGS = -g -Wall -pedantic -std =c11
#CFlAGS = -O -Wall -pedantic -std =c11

Source: Source.o interactive.o readfile.o

Source.o interactive.o readfile.o: structs.h readfile.h interactive.h

clean:
		rm -f *.o core Source

run: Source
		./Source zip.txt 25

debug: Source
		valgrind --leak-check=yes ./Source zip.txt 25