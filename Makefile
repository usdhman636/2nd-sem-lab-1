CC = gcc
CFLAGS = -Wall -Wextra -O2

OBJ = main.o int.o float.o vector.o errors.o io.o

program: $(OBJ)
	$(CC) $(CFLAGS)  -o run $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o run

run: program
	./run
