default: all

CC = mpicc
FLAGS = -O3 -Wall

all: bcast_reduce scatter_gather

bcast_reduce: mpi_bcast_reduce.c
	$(CC) -o $@ $^ $(FLAGS) -lm

scatter_gather: mpi_scatter_gather.c
	$(CC) -o $@ $^ $(FLAGS) -lm

clean:
	rm -f $(OBJ) $(EXE)

