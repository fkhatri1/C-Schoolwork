CC=gcc 
CFLAGS=-Wall -pedantic -ansi

all: project2.c mapobject.o basiclist.o map.o
	$(CC) $(CFLAGS) project2.c mapobject.o basiclist.o map.o -o project2

mapobject.o: mapobject.c
	$(CC) $(CFLAGS) -c mapobject.c

map.o: map.c
	$(CC) $(CFLAGS) -c map.c

basiclist.o: basiclist.c
	$(CC) $(CFLAGS) -c basiclist.c

clean:
	rm -f *.o *~ project2.exe
