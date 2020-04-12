#include "stdio.h"
#include "fcntl.h"
#include "assert.h"
#include "string.h"

int main (int argc, char *argv[]) {

  
  assert(argc > 1) ;
  char buff[100]; 
  char i = 0; 

  memset(buff, 0, 100); 

  printf("Input: %s\n",argv[1]); 
  printf("buff -> : %s\n", buff);

  int fp = open("/dev/driverTest", O_RDWR);

  write(fp, argv[1], strlen(argv[1]));
  
  while(read (fp, &buff[i++], 1));
  
  printf("Reversed by the driver: %s\n", buff);
  

}