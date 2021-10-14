#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Duplicating a file descriptor
 */

int main(){

    int fd;
    int new_fd;
    fd  = open("newFile.log", O_RDWR | O_CREAT, 0767);

    if (fd == -1){
        printf("\nopen() was failed - errno = \n");
        perror ("Error Occurred");
        exit(1);
    }
    else { printf("\n Open() system call executed successfully");}

    //duplicating file descriptor
new_fd = dup(fd);

    printf("\n new fd() value after dup() is (%d)\n",new_fd);

    write(new_fd, "Writing using new fd,but will be written to the old",50);
    
    close(fd);
    close(new_fd);
}
