CC = clang
CFLAGS = -Wall -Werror -Wpedantic -Wextra
LFLAGS = -lm

all: e.o newton.o mathlib-test euler.o madhava.o viete.o bbp.o

mathlib-test: mathlib-test.o e.o newton.o euler.o madhava.o viete.o bbp.o
	$(CC) -o mathlib-test mathlib-test.o newton.o e.o euler.o madhava.o viete.o bbp.o $(LFLAGS)

mathlib-test.o: mathlib-test.c mathlib.h
	$(CC) $(CFLAGS) -c mathlib-test.c

newton.o: newton.c mathlib.h
	$(CC) $(CFLAGS) -c newton.c

e.o: e.c mathlib.h
	$(CC) $(CFLAGS) -c e.c

euler.o: euler.c mathlib.h
	$(CC) $(CFLAGS) -c euler.c

madhava.o: madhava.c mathlib.h
	$(CC) $(CFLAGS) -c madhava.c

viete.o: viete.c mathlib.h
	$(CC) $(CFLAGS) -c viete.c

bbp.o: bbp.c mathlib.h
	$(CC) $(CFLAGS) -c bbp.c

clean:
	rm -f mathlib-test *.o

format:
	clang-format -i -style=file *.[c,h]
