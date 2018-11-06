// This code is modified from 
// http://mpitutorial.com/tutorials/mpi-send-and-receive/
#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
  int token, size, rank, prev, next;
  
  MPI_Init(&argc, &argv); 
  MPI_Comm_size(MPI_COMM_WORLD, &size); 
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
  
  prev = (rank-1+size)%size; // receive from who?
  next = (rank+1)%size;      // send to who? 

  if (rank == 0) {
    token = -1;
    MPI_Send(&token, 1, MPI_INT, next, 0, MPI_COMM_WORLD);
    MPI_Recv(&token, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process %d received token %d from process %d\n", rank, token, prev);
  } else {
    MPI_Recv(&token, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process %d received token %d from process %d\n", rank, token, prev);
    MPI_Send(&token, 1, MPI_INT, next, 0, MPI_COMM_WORLD);
  }
  
  MPI_Finalize();
  return 0;
}
