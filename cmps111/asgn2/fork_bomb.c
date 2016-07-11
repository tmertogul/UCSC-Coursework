// Tim Mertogul
// Prateek Chawla
// Adel Danandeh
// CS 111 Winter 16
// Testing the scheduler

#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int i, status, f, curr, max, children;
pid_t pid, cpid;

int main(int argc, char *argv[]) {
    int i;

    max = atoi (argv[1]);
    curr = 0;
    children = 0;

    for (i = 0; i < 10; i++) {
    	switch(pid = fork()) {

        // Error Code
        case -1: 
            perror("fork");
            exit(1);

        // Child Code
        case 0:        	
            printf("Child %d PID: %d\n", children, getpid());
            ++children;
            curr = 0;
            while(curr < max){
               ++curr;
               if ((curr % 100000) == 0 || (max - curr) < 10){
                   printf("%d cPID: %d, %12d to go\n", children, getpid(), (max - curr));
               }
            }
            break;

        // Parent Code
        default :
        	printf("Parent PID: %d\n", getpid());
            while(curr < max){
               ++curr;
               if (curr % 1000 == 0 || (max - curr) < 10){
                   printf("%d pPID: %d, %12d to go\n", children, getpid(), (max - curr));
               }
            }
            //while ((pid = wait(&status)) != -1){ }
            break;
        }
    }
    while ((pid = wait(&status)) != -1){ }
    printf("Done\n");
    return (0);
}
