#include <stdlib.h>
#include <stdio.h>

typedef struct {
  /* number of entries in array */
  int size;
  
  /* starting location in memory*/
  int* pt_data;

}array;

array arrayConstructor(int size){
  array a;

  a.size = size;

  //allocate enough storage on the heap to store size integers
  a.pt_data = 
    (int*) malloc(size*sizeof(int));

  return a;
}

array arrayReader(char *fileName){

  array a;

  //open file with name filename for reading
  FILE *pt_file = fopen(fileName, "r");
  int size;
  fscanf(pt_file, "%d", &size);

  /*set up storage for array*/
  a = arrayConstructor(size);

  //loop through array and read size ints
  for (n=0;n<size;++n){
    /* read one integer*/
    fscanf(pt_file, "%d", a.pt_data+n);
  }

  //close file when done
  fclose(pt_file);

  return a;
}

void arrayPrint(array a){
  int n;
  
}


int main(){

  int size = 100;

  array a = arrayConstructor(size);

  array b = arrayReader("array.file");

  arrayPrint(b);
}


