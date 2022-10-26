#include <stdio.h>
#include <stdlib.h>
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
    if (argc != 2 && argc !=3)
    {
        fprintf(stderr,"usage: %s path\n",argv[0]);
        exit(1);
    }
    if (strcmp(argv[2], "-i")==0){
        char a;
        printf("Are you sure you want to remove this file? (y/n)");
        scanf("%c",&a);
        if (strcmp(a,"y")==0){
            if (ftw(argv[1], rmFiles,10) < 0)
            {
                perror("ERROR: ntfw");
                exit(1);
            }
        }
        else{
            printf("File not removed.\n")
            return 0;
        }
    }
    return 0;
}
