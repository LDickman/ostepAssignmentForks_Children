#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

// Prints both parent and child on same line on file - proving that the two are writing at the same time 
 int main(int argc, char *argv[]) {
    int fd;
    char buffer[26];

    fd = open("hw1-2file.txt", O_CREAT | O_WRONLY, 0700); /// premission to write and read

    if (fd < 0) {
        fprintf(stderr, "File failed to create and open\n");
        exit(1);
    }

    int rc = fork();
    if (rc < 0) {
    // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        //Child Process
        write(fd, "Child Process!\n", 15);
        read(fd, buffer, 13);
        printf("Child buffer: %s\n", buffer);
    } else {
        // parent process
        read(fd, buffer, 13);
        write(fd, "Parent Process!\n", 15);
        printf("Parent buffer: %s\n", buffer);
    }

    close(fd);
    return 0;
 }


// // Writes child first and parent second in file
// int main(int argc, char *argv[]) {
//     int fd;
//     char buffer[26];

//     fd = open("hw1-2file.txt", O_CREAT | O_WRONLY, 0700); /// premission to write and read

//     if (fd < 0) {
//         fprintf(stderr, "File failed to create and open\n");
//         exit(1);
//     }

// 	int rc = fork();
//  	if (rc < 0) {
//  	// fork failed
//  		fprintf(stderr, "fork failed\n");
//  		exit(1);
//  	} else if (rc == 0) {
//         //Child Process
//  		write(fd, "Child Process!\n", 15);
//         read(fd, buffer, 13);
//         printf("Child buffer: %s\n", buffer);
//  	} else {
//  		// parent process
//         wait(NULL);
//         read(fd, buffer, 13);
//  		write(fd, "Parent Process!\n", 15);
//         printf("Parent buffer: %s\n", buffer);
//     }

//     close(fd);
//  	return 0;
//  }