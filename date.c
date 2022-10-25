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
	else if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			//Checking if option is passed
			//Options supporting: a, l
			int op_a = 0, op_l = 0;
			char *p = (char*)(argv[1] + 1);
			while(*p){
				if(*p == 'a') op_a = 1;
				else if(*p == 'l') op_l = 1;
				else{
					perror("Option not available");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			_ls(".",op_a,op_l);
		}
	}
	return 0;
}
