#include <stdio.h>
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
