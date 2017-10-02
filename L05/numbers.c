#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  /* initialize MPI as soon as you initialize your program */
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  MPI_Comm_rank(MPI_COMM_WORLD, &size);
  
  int dataCount = 10, n;
  int sourceRank = 0;
  int destRank = size - 1, tag = 999;
  if(rank == 0){
	int *dataOut = (int*) malloc(dataCount*sizeof(int));

	for(n = 0; n<dataCount;n++){
	  dataOut[n] = 2*n;
	}

	MPI_Send(dataOut, dataCount, MPI_INT, destRank, tag, MPI_COMM_WORLD);

        free(dataOut);
  } 


  if(rank == destRank){
    int *dataOut = (int*) malloc(dataCount*sizeof(int));
    MPI_Recv(dataCount,
    MPI_INT, sourceRank, tag, MPI_COMM_World, &status);
    free(dataIn);
  }
  /*All instances of this API program must enter the "finalize" 
  function before exiting*/
  MPI_Finalize();
  exit(0);
  return 0;

}
