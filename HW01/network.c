#include "stdio.h"
#include "stdlib.h"

typedef struct{

  // Start your Q4.1 code

  int nodeNumber; //total number of nodes
  int maxNumNodes; //max number of nodes one node can be connected to
  int* pt_numOfConnections;  //pointer to an array that has number of connections a node has
  int* pt_sourceOfConnection; //pointer to an array that has source of each connection
  int* pt_destOfConnection;  //pointer to an array that has destination of each connection
  double* pt_pageRankValues;  //pointer to an array that has page rank values

  // End your Q4.1 code

}Network;


Network networkReader(char* filename){

  // Start your Q4.2 code
  
  Network net;
  FILE input = fopen(filename, "r");
  int scanned;
  int numOfConnections[100];
  int sourceOfConnection[100];
  int destOfConnection[100];
  int i = 0;
  fscanf(input, "%d", "%d", &nodeNumber, &maxNumNodes);
  while(fscanf(input, "%d", "%d", &sourceOfConnection[i], &destOfConnection[i]) != EOF){
	i++;
  }
  int j = 0;
  for(j; j < i; j++){
	numOfConnections[];
  }
  
  pt_numOfConnections = &numOfConnections;
  pt_sourceOfConnection = &sourceOfConnection;
  pt_destOfConnection = &destOfConnection;

  printf(nodeNumber);
  printf(maxNumNodes);
  
  
  //close file when done
  fclose(input);
  
  // End your Q4.2 code

}

int main(int argc, char** argv){

  // Reads the input filename of the data file
  char* filename = argv[1];

  // Reads the input of the node number, stores in i
  int i = atoi(argv[2]);

  // Start your Q4.3 code
  




  // End your Q4.3 code
}
