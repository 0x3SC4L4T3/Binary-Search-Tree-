CC=g++
CFLAGS=-I.
DEPS = BinarySearchTreeInterface.h Pokemon.h
OBJ = Pokemain.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Lab09: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
     
