#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{

  // Start your code
  int nodes;                 //total number of nodes
  int maxConnects;           //max number of nodes one node can be connected to
  int* pt_connectCount;      //pointer to an array that has number of connections a node has
  int* pt_source;            //pointer to an array that has source of each connection
  int* pt_dest;              //pointer to an array that has destination of each connection
  double* pt_oldPageRank;
  double* pt_newPageRank;
  // End your code

}Network;


Network networkReader(char* filename){

  // Start your code
  Network g;
  int i, j, temp;
  FILE *fp;
  int source;
  int dest;
  int count = 0;

  fp = fopen(filename, "r");
  fscanf(fp, "%d,", &g.nodes);
  temp = fscanf(fp, "%d,", &g.maxConnects);

  g.pt_connectCount = (int*)calloc(g.nodes, sizeof(int));
  g.pt_source = (int*)calloc(g.nodes * g.maxConnects, sizeof(int));
  g.pt_dest = (int*)calloc(g.nodes * g.maxConnects, sizeof(int));

  g.pt_oldPageRank = (double*)calloc(g.nodes, sizeof(double));
  g.pt_newPageRank = (double*)calloc(g.nodes, sizeof(double));
 
  // Check if fscanf has read to the End of File
  do{
    temp = fscanf(fp, "%d,%d,", &source, &dest);     
    if(temp==EOF) break;
    g.pt_source[count]=source;
    g.pt_dest[count]=dest;
    g.pt_connectCount[g.pt_source[count]]++;
    count++;
  }while(temp != EOF);

  fclose(fp);

  return g;
  // End your code
}

double computeDiff(Network net){
  /* Q3.3 Code */
  int k = 0;
  double manip = 0.0;
  for (k; k < net.nodes; k++) {
    manip += pow(net.pt_newPageRank[k] - net.pt_oldPageRank[k], 2);
  }
  sqrt(manip);

  return manip;
  /* End Q3.3 Code */
}

double updatePageRank(Network net, double d){
  /* Q3.2 Code */
  int i = 0;
  int j = 0;
  double constant = (1.0 - d)/net.nodes;
  int size = 0; //number of total connections

  for (i;i < net.nodes; i++) { 
    size += net.pt_connectCount[i];
    net.pt_oldPageRank[i] = net.pt_newPageRank[i];
    net.pt_newPageRank[i] = constant;
  }

  for (j; j < size; j++) {
    net.pt_newPageRank[net.pt_dest[j]] += d * (net.pt_oldPageRank[net.pt_source[j]] / net.pt_connectCount[net.pt_source[j]]);
  }
  


  return computeDiff(net);
  /* End Q3.2 Code */
}


void computePageRank(Network net, double tol, double d){
  /* End Q3.4 Code */
  int l = 0;
  double init = 1.0/net.nodes;
  double x = 0.0;

  for (l; l < net.nodes; l++){
    net.pt_oldPageRank[l] = init;
    net.pt_newPageRank[l] = init;
  }
  
  do {
    x = updatePageRank(net, d);
  } while(x >= tol);
  /* End Q3.4 Code */
}


int main(int argc, char** argv){

  // Reads the filename of the data file
  char* filename = argv[1];

  // Reads the input of the node number, stores in i
  int i = atoi(argv[2]);
  double tol = atof(argv[3]);
  double d = atof(argv[4]);

  //Start your code

  
  Network network_t = networkReader(filename);

//  for (){
  computePageRank(network_t, tol, d);
  printf("The PageRank of node %d is %lf \n", i, network_t.pt_newPageRank[i]);


  return 0;
}
