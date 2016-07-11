// Tim Mertogul
// Prateek Chawla
// Adel Danandeh
// CS 111 Winter 16
// Testing the scheduler

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>
#include <fcntl.h>
//#include <sys/stat.h> 

int main(int argc, char* argv[]){
    char buf[20];
    size_t nbytes;
    size_t bytes_read;
    int fdin = open(argv[1],O_RDONLY); 
    int fdout = open(argv[2],O_WRONLY | O_CREAT, 0644); 
    nbytes = sizeof(buf);
    if (fdin >= 0 ){
        while( (bytes_read = read(fdin, buf, nbytes)) > 0){
            write(fdout, buf, bytes_read);
        }        
    } else {
        perror("cat: Error");
    }
    close(fdin);
    close(fdout);
    return 0;
}
 

