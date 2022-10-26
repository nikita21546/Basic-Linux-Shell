#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define BUF_LEN 256

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
	else if (argc == 2)
	{
		if (arg[1])
		{
			char buf[BUF_LEN] = {0};
   			time_t rawtime = time(NULL);
    			if (rawtime == -1) {
        			puts("The time() function failed");
        			return 1;
    			}
       			struct tm *ptm = localtime(&rawtime);
       			if (ptm == NULL) {
				puts("The localtime() function failed");
        			return 1;
    			}
    			strftime(buf, BUF_LEN, argv[1], ptm);
    			puts(buf);
		}
		else{
			perror("Option not available");
			exit(EXIT_FAILURE);
		}
	}
}
