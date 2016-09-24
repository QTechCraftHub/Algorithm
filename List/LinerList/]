
CC = gcc

object = main.o linerList.o

main : $(object)
	$(CC) -o main $(object)

main.o : main.c linerList.c linerList.h
	$(CC) -c -o main.o main.c

linerList.o : linerList.c linerList.h
	$(CC) -c -o linerList.o linerList.c

clean:
	rm main $(object)
