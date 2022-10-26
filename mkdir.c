// C++ program to create a directory in Linux
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)

{
    if (argc==2){
        if (mkdir(argv[1], 0777) == -1)
            printf("Error");
        printf("Directory created");
    }
    else if (argc==3){
        if (mkdir(argv[1], 0777) == -1)
            printf("Error");
        if (mkdir(argv[2], 0777) == -1)
        printf("Error");
        printf("Directory created");
    }
    else if (argc==3){
        if (mkdir(argv[1], 0777) == -1)
            printf("Error");
        if (mkdir(argv[2], 0777) == -1)
        printf("Error");
        if (mkdir(argv[3], 0777) == -1)
        printf("Error");
        printf("Directory created");
    }
}
