#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// /// wait returns child PID   - Now write a program that uses wait() to wait for the child process to finish in the parent. 
int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc <0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc ==0) {
		printf("Child says: Hello!\n");
		printf("Child ID: (pid:%d)\n", (int) getpid());
	} else {
		int rc_wait = wait(NULL);
		printf("Parent says: Goodbye\n");
		printf("The retrun code of wait is %d\n", rc_wait); 
	}
	return 0;
}



// /// wait() returns -1 when in the child
// int main(int argc, char *argv[]) {
// 	int rc = fork();
// 	if (rc < 0 ){
// 		fprintf(stderr, "fork failed\n");
// 		exit(1);
// 	} else if (rc == 0) {
// 		int rc_wait = wait(NULL);
// 		printf("I am child and retrun code of wait is %d\n", rc_wait);
// 	} else {	
// 		printf("I am parent.\n");
// 	}
// 	return 0;
// }