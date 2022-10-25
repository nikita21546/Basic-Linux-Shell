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
    if (argc != 2)
    {
        fprintf(stderr,"usage: %s path\n",argv[0]);
        exit(1);
    }
    if (nftw(argv[1], rmFiles,10, FTW_DEPTH|FTW_MOUNT|FTW_PHYS) < 0)
    {
        perror("ERROR: ntfw");
        exit(1);
    }
    return 0;
}
