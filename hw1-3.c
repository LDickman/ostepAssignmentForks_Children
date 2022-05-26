#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

//Using wait()
int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc <0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc ==0) {
		printf("Child says: Hello!\n");
	} else {
		wait(NULL);
		printf("Parent says: Goodbye\n");
	}
	return 0;
}

//Through file
// int main(int argc, char *argv[]) {
//     int fd;
//     char buffer[20];

//     fd = open("hw1-3file.txt", O_CREAT | O_WRONLY, 0700); /// premission to write and read

//     if (fd < 0) {
//         fprintf(stderr, "File failed to create and open\n");
//         exit(1);
//     }

//     int rc = fork();
//     if (rc < 0) {
//     // fork failed
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc != 0) {
//         //Child Process
//         write(fd, "Hello!\n", 7);
//         read(fd, buffer, 10);
//         printf("Child buffer: %s\n", buffer);
//     } else {
//         // parent process
//         read(fd, buffer, 10);
//         write(fd, "Goodbye!\n",8);
//         printf("Parent buffer: %s\n", buffer);
//     }

//     close(fd);
//     return 0;
//  }