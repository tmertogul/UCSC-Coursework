/* Tim Mertogul
*  CS 111 Operating Systems
*  Darrell Long
*  ASG 0
*  Cat program
*  Lots of bits and pieces of this project were taken from 
*  the man pages specified in the assignment PDF
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>
#include <fcntl.h>
//#include <sys/stat.h> 

int main(int argc, char* argv[]){
    for (int i = 1; i < argc; i++){
    	char buf[20];
    	size_t nbytes;
    	size_t bytes_read;
    	int fd = open(argv[i],O_RDONLY); 
        nbytes = sizeof(buf);
    	if (fd >= 0 ){
            while( (bytes_read = read(fd, buf, nbytes)) > 0){
                write(STDOUT_FILENO, buf, bytes_read);
            }            
        } else {
            perror("cat: Error");
        }
		close(fd);
    }
    return 0;
}
 
