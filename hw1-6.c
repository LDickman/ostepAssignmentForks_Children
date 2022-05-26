#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc <0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("Child PID: %d\n", (int) getpid());
	} else {
		int rc_wait = waitpid(-1, NULL, 0);
		printf("Parent Process Wait PID: (rc_wait:%d)\n", rc_wait); 
	}
	return 0;
}