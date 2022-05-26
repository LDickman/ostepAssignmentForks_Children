#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int x = 10;
	printf("Starting value is %d\n", x);
	int rc = fork();
	if (rc <0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc ==0) {
		printf("This is the child Process and current value is at %d\n", x);
		x = x + 2;
		printf("After increment by 2 child value is %d\n", x);
	} else {
		printf("This is the parent Process and current value is at %d\n", x);
		x = x + 5;
		printf("After increment by 5 parent value is %d\n", x);
	}
	return 0;
}
