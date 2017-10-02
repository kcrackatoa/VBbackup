#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"


void barrier(){
   int rank, size, alive;
   int sizeBuffer = 1;
   int *sendBuffer = (int*) calloc(sizeBuffer, sizeof(int));
   int *recvBuffer = (int*) calloc(sizeBuffer, sizeof(int));
   MPI_Comm_size(MPI_COMM_WORLD, &size);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);


   if (rank == 0){
      sendBuffer[0] = 1;
   }
   /* number of alive processes*/
   alive = 1;

   while(alive < size){
      if (rank < alive){
         int dest = rank + alive;
         MPI_Send(sendBuffer, sizeBuffer, MPI_INT, dest, tag, MPI_COMM_WORLD);
      }
      if(rank >= alive && rank < 2*alive){
	 int source = rank - alive;
         if(source >= 0)
         MPI_Recv(recvBuffer, sizeBuffer, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
      }
   alive *= 2;
   }
}
