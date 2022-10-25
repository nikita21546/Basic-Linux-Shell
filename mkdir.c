// C++ program to create a directory in Linux
#include <algorithm>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

int main(int argc, char **argv)

{
    if (mkdir(argv[1], 0777) == -1)
        cerr << "Error : " << strerror(errno) << endl;

    else
        cout << "Directory created";
}
