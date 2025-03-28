CC = gcc
CFLAGS = -Wall -g

all: app

app: main.o temp_api.o
	$(CC) $(CFLAGS) -o app main.o temp_api.o

main.o: main.c temp_api.h
	$(CC) $(CFLAGS) -c main.c

temp_api.o: temp_api.c temp_api.h
	$(CC) $(CFLAGS) -c temp_api.c

clean:
	rm -f *.o app