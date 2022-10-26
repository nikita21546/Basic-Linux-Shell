#include<fcntl.h> 
#include<stdio.h>
#include<stdlib.h>
main(int argc,char*argv[])
{
  if(argc!=2 && argc!=3){ //checks if two arguments are present
    printf("\nThe syntax should as be follows");
    printf("\nCommandname filetoread\n");
    exit(1);
  }
  if (argc==2){
    int fdold,count;
    char buffer[2048]; //characer buffer to store the bytes
    fdold=open(argv[1], O_RDONLY);
    if(fdold==-1)
     {
        printf("cannot open file");
        exit(1);
      }
    while((count=read(fdold,buffer,sizeof(buffer)))>0) 
    {
      printf("%s",buffer);
    }
    exit(0);
  }
  else if (argc==3){
    if (!strstr("-n",argv[1])){
      int fdold,count, fdold2, count2;
      char buffer[2048];
      char buffer2[2048];
      fdold=open(argv[1], O_RDONLY);
      fdold2=open(argv[2], O_RDONLY);
      if(fdold==-1 || fdold2==-1)
      {
        printf("cannot open file");
        exit(1);
      }
      while((count=read(fdold,buffer,sizeof(buffer)))>0) 
      {
        printf("%s\n",buffer);
      }
      while((count2=read(fdold2,buffer2,sizeof(buffer2)))>0) 
      {
        printf("%s\n",buffer2);
      }
    exit(0);
    }
    else{
        int fdold;
        char buffer[2048];
        int size=0;
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
        int count=1;
        FILE *fp;
        fp= fopen(argv[2], "r");
        fdold=open(argv[2], O_RDONLY);
        if(fdold==-1)
        {
          printf("cannot open file");
          exit(1);
        }
        while (fgets(buffer, 255, fp)) {
          printf("%d. %s\n",count, buffer);
          count++;
        }
        exit(0);
      }
    }
  }
}
