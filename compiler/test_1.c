#include "global_0.h"

int main(){
  init();
  int x;
  while((x = lexan()) != DONE){
      printf("token = %d, tokenval = %d\n", x, tokenval);
  }
  exit(0);
}