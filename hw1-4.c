#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();

    if (rc <0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child 
        printf("Child Process\n");
        
        //execl("/bin/ls", "ls", NULL);         /// prints out everything within the hw1 file on the terminal
        //execlp("ls", "ls", NULL);             /// prints out everything within the hw1 file on the terminal

        char * const envp[] = {NULL};           /// needed as part of the parameter for execle and execvpe
        //execle("/bin/ls", "ls", NULL, envp);    /// prints out everything within the hw1 file on the terminal
        
        char * const argv[] = {"ls", NULL};    /// needed as part of the parameter for execv, execvp, and execvpe
        //execv("/bin/ls", argv);               /// prints out everything within the hw1 file on the terminal
        //execvp("ls", argv);                   /// prints out everything within the hw1 file on the terminal

        execvpe("ls", argv, envp); /// says error but it still prints out everything within the hw1 file on the terminal
    }
    else { // parent
        wait(NULL);
        printf("Parent Process\n");
    }
}

