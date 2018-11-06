CC = mpicc
FLAGS = -O3 -Wall

all: hello2 cpi split group 

hello2: mpi_hello2.c
	$(CC) -o $@ $^ $(FLAGS)

cpi: mpi_cpi.c
	$(CC) -o $@ $^ $(FLAGS) -lm

split: mpi_split.c
	$(CC) -o $@ $^ $(FLAGS)

group: mpi_group.c
	$(CC) -o $@ $^ $(FLAGS)

clean:
	rm -f $(OBJ) $(EXE)

