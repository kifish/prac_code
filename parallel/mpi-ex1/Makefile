CC = mpicc
FLAGS = -O3 -Wall

hello: mpi_hello.c
	$(CC) -o $@ $^ $(FLAGS)

ring: mpi_ring.c
	$(CC) -o $@ $^ $(FLAGS)

clean:
	rm -f $(OBJ) $(EXE)

