#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  /* initialize MPI as soon as you initialize your program */
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  MPI_Comm_size(MPI_COMM_WORLD, &size);

  printf("hello world from process %0d\n",
	rank, size);

  if(rank ==0){
    // only rank 0 does this
    int i;
    double j;
    for(i=0; i < 100; i++){
	j += i/(double)(rank+1);
    }
    printf("rank %d computed j=%lf\n", rank, j);
  }

  /*All instances of this API program must enter the "finalize" 
  function before exiting*/
  MPI_Finalize();
  exit(0);
  return 0;

}
