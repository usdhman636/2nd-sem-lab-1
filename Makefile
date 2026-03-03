CC = gcc
CFLAGS = -Wall -Wextra -O2

OBJ = main.o int.o float.o

program: $(OBJ)
	$(CC) $(CFLAGS)  -o run $(OBJ)

src/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o run

run: program
	./run
