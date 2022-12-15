CC = clang
CFLAGS = -Wall -Werror -Wpedantic -Wextra
LFLAGS = -lm

all: insert.o sorting stats.o shell.o heap.o quick.o

sorting: sorting.o insert.o stats.o shell.o heap.o quick.o
	$(CC) -o sorting sorting.o insert.o stats.o shell.o heap.o quick.o $(LFLAGS)

sorting.o: sorting.c 
	$(CC) $(CFLAGS) -c sorting.c

insert.o: insert.c stats.h insert.h
	$(CC) $(CFLAGS) -c insert.c

stats.o: stats.c stats.h
	$(CC) $(CFLAGS) -c stats.c

shell.o: shell.h shell.c stats.h
	$(CC) $(CFLAGS) -c shell.c

heap.o: heap.h heap.c stats.h
	$(CC) $(CFLAGS) -c heap.c

quick.o: quick.h quick.c stats.h
	$(CC) $(CFLAGS) -c quick.c

clean:
	rm -f sorting *.o

format:
	clang-format -i -style=file *.[c,h]

