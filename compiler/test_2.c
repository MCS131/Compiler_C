#include "global_0.h"

int main(){
    init();
    int i, token, lastloc = 0;
    extern int lastentry;

    while((token = lexan()) != 261){
      if (symtable[lastentry].location == NONE){
        symtable[lastentry].location = lastloc;
        lastloc = lastloc + 1;
      }
    }    

    printf("            ****Kigouhyou****\n");
    printf("    ID Name|       token|     location\n");
    for (i = 1; i < lastentry; i++){
      printf("%10s |%11d |%10d\n",
              symtable[i].lexptr, symtable[i].token, symtable[i].location);
    }

    exit(0);
}