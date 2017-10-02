#include <stdio.h>

void myprintf(char *message){
  
  while((*message)!= '\0'){
  char c = *message;
  printf("%c\n", c);

  message = message+1;
  }
}

void passByCopy(int n){
  n = n+1;
}


void passByPointer(int* pt_n){
  (*pt_n) = (*pt_n)+1;
}

/* main function */
int main(){
  int n = 6;
  printf("hello world\n");

  myprintf("hello world again\n");

  passByCopy(n);

  passByPointer(&n);

  printf("n=%d\n", n);
}
