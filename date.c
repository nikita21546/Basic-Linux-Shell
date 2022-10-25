#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, const char *argv[])
{
	if (argc == 1)
	{
		time_t now = time(&now);
		if (now == -1) {
			puts("The time() function failed");
    		}
		struct tm *ptm = gmtime(&now);
		if (ptm == NULL) {
			puts("The gmtime() function failed");
		}
		printf("UTC time: %s", asctime(ptm));
		return 0;
	}
}
