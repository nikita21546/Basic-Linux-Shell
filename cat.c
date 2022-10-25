#include<fcntl.h> //header file for file operations
#include<stdio.h>
#include<stdlib.h>
main(int argc,char*argv[])
{
  if(argc!=2){ //checks if two arguments are present
    printf("\nThe syntax should as be follows");
    printf("\nCommandname filetoread\n");
    exit(1);
  }
  int fdold,count;
  char buffer[2048]; //characer buffer to store the bytes
  fdold=open(argv[1], O_RDONLY);
  if(fdold==-1)
  {
    printf("cannot open file");
    exit(1);
  }
  while((count=read(fdold,buffer,sizeof(buffer)))>0) //displaying the content
  {
    printf("%s",buffer);
  }
  exit(0);
}
