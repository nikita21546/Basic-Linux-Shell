// C++ program to create a directory in Linux
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)

{
    if (mkdir(argv[1], 0777) == -1)
        printf("Error");

    else
        printf("Directory created");
}
