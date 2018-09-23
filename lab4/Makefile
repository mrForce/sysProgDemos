#define more variables so it is easier to make changes
CC=clang
CFLAGS= -pg -Wall -std=c99 -lm
TARGETS=matrix_demo matrix matrix_wait matrix_function matrix_cachegrind

all: $(TARGETS)

matrix_demo: matrix_demo.c
	$(CC) $(CFLAGS) -o $@ $@.c

matrix_cachegrind: matrix_cachegrind.c
	$(CC) $(CFLAGS) -o $@ $@.c

matrix_function: matrix_function.c
	$(CC) $(CFLAGS) -o $@ $@.c


matrix_wait: matrix_wait.c
	$(CC) $(CFLAGS) -o $@ $@.c
matrix: matrix.c
	$(CC) $(CFLAGS) -o $@ $@.c

clean:
	rm -rf *.o *~ $(TARGETS)
