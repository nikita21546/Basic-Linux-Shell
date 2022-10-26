#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ftw.h>

static int rmFiles(const char *pathname, const struct stat *sbuf, int type, struct FTW *ftwb)
{
    if(remove(pathname) < 0)
    {
        perror("ERROR: remove");
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        if (ftw(argv[1], rmFiles,10) < 0)
        {
            perror("ERROR: ntfw");
            exit(1);
        }
        
    }
    else if(argc==3){
        if (strcmp(argv[1],"-f")==0){
            if (ftw(argv[2], rmFiles,10) < 0)
            {
                perror("ERROR: ntfw");
                exit(1);
            }
        }
        else if (strcmp(argv[1],"-i")==0){
            printf("Are you sure you want to remove this file? (y/n)");
            if (getchar()=="y"){
                if (ftw(argv[2], rmFiles,10) < 0)
                {
                    perror("ERROR: ntfw");
                    exit(1);
                }
            }
        }
        else{
            printf("File not removed.\n");
            exit(1);
        }
    }
    else{
        fprintf(stderr,"usage: %s path\n",argv[0]);
        exit(1);
    }
    return 0;
}
