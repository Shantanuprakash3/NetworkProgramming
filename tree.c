/*
Write a program tree.c for the following requirement.

Take input n
on command-line.

Parent creates n
children at level1.

Each child in-turn creates n-1 children at level2. Each chile at level2 creates n-2 children at level3. This continues until n reaches 0.

Each child prints it level, its pid, parent's pid, its
position i.e. 2 in
if it is P2, and those many dots ended by new line.
Then it exits.

Every process waits until all its children
are exited and only then it will print. Parent exits
printing "\nAll Children Exited\n".

*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int lvl=0;
void makechild(int n){
	
	pid_t pid;
	int i,j;
	if (n>=0)
	{
		for (i = 1; i <= n; i++) {
		pid = fork();
 		if (pid < 0) {
    		  perror("fork");
    		  abort();
  		  } else if (pid == 0) {
			lvl++;
		      	makechild(n-1);
			printf("%d   %d     %d   %d", lvl ,getpid(), getppid(), i);
			printf(" ");
			
			for (j = 0; j < i; ++j)
			{
				printf(".");
			}
			printf("\n");

		    	exit(0);
		  } else {
			wait(NULL);
			  }
		}
	}
}
int main(int argc, char* argv[]){
	
	int n=atoi(argv[1]);
	printf("Level pid ppid Position dots\n");
	makechild(n);
	printf("%d   %d     %d   %d", 0 ,getpid(), getppid(), 1);
			printf("\n");
			printf("\nAll Children Exited\n");
	int i;
	
	
	return 0;
}
