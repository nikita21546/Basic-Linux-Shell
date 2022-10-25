#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main (void) {

   int c = 0; 
   int cr;
  while (c != EOF) 
    { 
      printf("\n Enter input: "); 
      c = getchar(); 
      cr = getchar();  /* Read and discard the carriage return */
      putchar(c); 
    } 

}
