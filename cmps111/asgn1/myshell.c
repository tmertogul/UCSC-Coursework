// Tim Mertogul
// tmertogu
// CS 111 Winter 16
// MakeFile for ASG 1, Simple Shell

#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

extern char **getline();
extern int MAX_ARGS;
int i, status, f;
int fd_in, fd_out;
int fd_pipe[2];
pid_t pid, cpid;


int child_fork(char *args[]){
    //printf("Child PID: %d\n", getpid());
    if(args[0] == NULL){ exit(0); } else {
    for(i = 0; args[i] != NULL; i++) { 
        switch(*args[i]){
        case '>' : 
            // Redirect output to the file after ">" 
            fd_out = open(args[i+1], O_WRONLY | O_CREAT, 0644);
            if(fd_out == -1){
                perror("open");
                exit(1);                
            }
            if(dup2(fd_out, 1) == -1){
                perror("dup2");
                exit(1);
            }
            args[i++] = NULL;
            args[i] = " ";
            break;

        case '<' : 
            // Redirect output to the file after "<" 
            fd_in = open(args[i+1], O_RDONLY);
            if(fd_in == -1){
                perror("open");
                exit(1);                
            }
            if(dup2(fd_in, 0) == -1){
                perror("dup2");
                exit(1);
            }
            args[i++] = NULL;
            args[i] = " ";
            break;

        case '|' : 
            // Open a pipe between two processes
            pipe(fd_pipe);
            switch(cpid = fork()){
            // Error Code
            case -1 :
                perror("fork");
                exit(1);

            // Child Code
            case 0 :
                dup2(fd_pipe[1], 1);
                close(fd_pipe[0]);
                while (i < MAX_ARGS){
                    args[i++] = NULL;
                }
                break;

            // Parent Code
            default :
                dup2(fd_pipe[0], 0);
                close(fd_pipe[1]);
                while ((pid = wait(&status)) != -1){ }

                args[i++] = NULL;
                for (int j = 0; j+i < MAX_ARGS; ++j){
                    args[j] = args[i+j];
                }
                if (args[0] != NULL){
                    f = child_fork(args);
                }
            } 
            break;

        default :
            if (strcmp(args[0], "exit") == 0) { exit(0); }
            break;
        }
        } }
    if(args[0] == NULL){ }
    else if(execvp(args[0], args) == -1){
       perror(args[0]);
       exit(1);
    }
    return 0;
}

int main() {
    //char buf[BUF_SIZE];
    char **args;
    //printf("Welcome to MyShell, by Tim Mertogul\n");
    while(1) {        
        printf("$: ");  // prompt for MyShell

        args = getline();

        switch(pid = fork()) {
        // Error Code
        case -1:
            perror("fork");
            exit(1);

        // Child Code
        case 0: 
            f = child_fork(args);
        // Parent Code
        default :
            //printf("Parent PID: %d\n", getpid());
            while ((pid = wait(&status)) != -1){ }
            if(args[0] == NULL){ }
            else if (strcmp(args[0], "exit") == 0) { exit(0); }
        }
    } 
}
