#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BUF_LEN 256

void _date(const char *dir,int op_a,int op_l, char* b) {
    
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
    
    memset(buf, 0, BUF_LEN);
    strftime(buf, BUF_LEN, b, ptm);
    puts(buf);       

    return 0;
}

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
		if (strstr('+D', arg[1]))
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
    			strftime(buf, BUF_LEN, "%m/%d/%Y", ptm);
    			puts(buf);
		}
		else{
			perror("Option not available");
			exit(EXIT_FAILURE);
		}
	}
}
