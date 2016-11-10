all: principal

run: principal
	./principal
	
circonference.o: circonference.c pi.h
	gcc -c circonference.c -Wall
	
surface.o: surface.c pi.h
	gcc -c surface.c -Wall
	
principal.o: principal.c circonference.h surface.h
	gcc -c principal.c -Wall
	
principal: principal.o circonference.o surface.o
	gcc principal.o circonference.o surface.o -o principal

clean:
	rm -f *.o
	rm principal
