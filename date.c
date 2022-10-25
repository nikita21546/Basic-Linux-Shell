//Used for basic input/output stream
#include <stdio.h>
//Used for handling directory files
#include <dirent.h>
//For EXIT codes and error handling
#include <errno.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, const char *argv[])
{
	if (argc == 1)
	{
		time_t now = time(NULL);
    
        if (now == -1) {
        
            puts("The time() function failed");
        }

        printf("%ld\n", now);

        return 0;
	}
}
