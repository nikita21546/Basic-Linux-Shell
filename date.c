#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
		if (argv[1][0] == '+')
		{
			int op_d = 0, op_l = 0;
			char *p = (char*)(argv[1] + 1);
			while(*p){
				if(*p == 'd') op_d = 1;
				else if(*p == 'l') op_l = 1;
				else{
					perror("Option not available");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			_date(".",op_a,op_l, argv[2]);
		}
	}
}
