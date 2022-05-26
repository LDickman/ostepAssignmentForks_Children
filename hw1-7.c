#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc < 0 ){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		close(STDOUT_FILENO);
		printf("Child Processor says: Can you see this?!\n");
	} else {
		wait(NULL);  /// Does not change the output of the code
		printf("Parent Processor\n");
	}
	return 0;
}