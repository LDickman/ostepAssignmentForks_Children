#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    int mypipefd[2]; // ariel integer
    int ret;
    ret = pipe(mypipefd);
    char buffer[20];
    
    if (ret < 0 ){
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0) {
        printf("Child-1 Process\n");
        write(mypipefd[1], "Hello there!", 12);

    } else {
        printf("Parent-1 Process\n");
        
        int rc2 = fork();
        if (rc2 < 0){
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc2 == 0) {
            printf("Child-2 Process\n");
            read(mypipefd[0], buffer, 15);
            printf("To Child-2, from Child-1 buffer: %s\n", buffer);

        } else {
            wait(NULL);
            printf("Parent-2 Process\n");
        }
    }
    return 0;
}