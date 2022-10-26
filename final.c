#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pthread.h>
#define MAX 128

void* thread_func(void* argument) {
	char *f1 = (char *) argument;
	system(f1);
	pthread_exit(NULL); // you could also return NULL here to exit no difference
}

char cmd[MAX], cwd[MAX];
char temp[MAX][MAX];
pid_t pid;
int flag = -1;
char PATH[MAX] = "/bin/";
char input_print[MAX];
int count;
char buf[MAX];

void set_prompt () {
    getlogin_r(buf,10);
    strcpy (input_print, buf);
    strcat (input_print, ":~");
    strcat (input_print, getcwd (cwd, sizeof (cwd)));
}

void handle_input () {
	printf ("%s\n", input_print);
	char *input = NULL;
        input = readline("");
	if (input == NULL) {
		printf ("Goodbye\n");
		exit (1);
	}
	if (strcmp (input, "exit") == 0) {
		printf ("Goodbye\n");
		exit (0);
	}
	add_history (input);
	strcpy (cmd, input);
	count = 0;
}

void change_prompt () {
    if (strstr (cmd, "PS1") != NULL) {
        char *t = strtok (cmd, "=");
        t = strtok (NULL, "=");
        strcpy (input_print, t);
        handle_input ();
    }
}

void set_path () {
	char *t = strtok (cmd, "=");
	t = strtok (NULL, "=");
	strcpy (PATH, t);
}

int handle_spaces () {
	char *t = strtok (cmd, " ");
	strcpy (temp[0], t);
	count++;
	t = strtok (NULL, " ");
	if (t == NULL) {
		return 0;
	}
	int i = 1;
	while (t != NULL) {
		strcpy (temp[i], t);
		i++;
		count++;
		t = strtok (NULL, " ");
	}
	return -1;
}

int check_prompt () {
	char *t = strtok (input_print, "~");
	t = strtok (NULL, "~");
	if (strcmp (t, getcwd (cwd, sizeof (cwd))) == 0) {
		return 1;
	}
	return 0;
}

void process_single () {
	char *ptr[] = {cmd, NULL};
	if (execv (cmd, ptr) == -1) {
		char c[MAX];
		strcpy (c, PATH);
		strcat (c, cmd);
		ptr[0] = c;
		if (execv (c, ptr) == -1) {
			perror ("error");
		}
	}
}

void process_multiple () {
	if (strcmp (temp[0], "cd") == 0) {
		if (check_prompt () == 1) {
			chdir (temp[1]);
			set_prompt ();
		}
		else {
			chdir (temp[1]);	
		}
		return;
	}
	char *ptr[] = {temp[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};	
	for (int i = 1; i < count; i++) {
		ptr[i] = temp[i];
	}
	if (execv (temp[0], ptr) == -1) {
		char c[MAX];
		strcpy (c, PATH);
		strcat (c, temp[0]);
		ptr[0] = c;
		if (execv (c, ptr) == -1) {
			perror ("error");
		}
	}
}

int main () {
	set_prompt ();
	while (1) {
		handle_input ();
		if (strstr (cmd, "PATH") != NULL) {
			set_path ();
		}	
		else if (strcmp (cmd, "cd") == 0) {
			chdir ("/home");
			set_prompt ();
		}
		else if (strstr (cmd, "PS1") != NULL) {
			change_prompt ();
			continue;
		}
		else {
			pid = fork ();
			if (pid == 0) {
				if (handle_spaces() == 0) {
                    			if (strstr(temp[0],"ls")){
						if (execl ("./ls", "./ls, NULL") == -1) {
							char c[MAX];
							strcpy (c, PATH);
							strcat (c, cmd);
							if (execl (c, c, NULL) == -1) {
								perror ("error");
							}
						}
                    			}
                			else if(strstr(temp[0],"date")){
						execl("./date","./date", NULL);
            				}
					else if(strstr(temp[0],"pwd")){
						if (execl (cmd, cmd, NULL) == -1) {
							char c[MAX];
							strcpy (c, PATH);
							strcat (c, cmd);
							if (execl (c, c, NULL) == -1) {
								perror ("error");
							}
						}
					}
					else {
						process_single ();
					}
				}
				else{
					if (strcmp (temp[0], "cd") == 0) {
						if (check_prompt () == 1) {
							chdir (temp[1]);
							set_prompt ();
						}
						else {
							chdir (temp[1]);	
						}
					}
					else if (strstr(temp[0],"ls")){
		        			execl("./ls","./ls", temp[1], NULL);
                			}
					else if (strstr(temp[0],"&tls")){
						pthread_t pid;
						pthread_create(&pid, NULL, fcaller, &cmd);
						pthread_join(pid, NULL);
                			}
    					else if(strstr(temp[0],"date")){
					    	execl("./date","./date", temp[1], NULL);
    					}
					else if(strstr(temp[0],"mkdir")){
						if (strstr("", temp[2])){
							execl("./mkdir", "./mkdir", temp[1], NULL);
						}
						else{
							execl("./mkdir", "./mkdir", temp[1], temp[2], NULL);
						}
            				}
					else if(strstr(temp[0],"rm")){
			    			execl("./rm","./rm", temp[1], NULL);
			                }	
					else if(strstr(temp[0],"cat")) {
						if (strstr("", temp[2])){
							execl("./cat", "./cat", temp[1], NULL);
						}
						else{
							execl("./cat", "./cat", temp[1], temp[2], NULL);
						}
					}
					else {
						process_multiple ();
					}
				}
			}
			else {
				wait (NULL);
			}
		}
	}
}
