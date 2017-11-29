#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main(int argc, char const *argv[]) {

    int fd;
    char * myfifo = "/tmp/myfifo";
    char buffer[MAX_BUF];

    int receivedNumber;

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    read(fd, buffer, MAX_BUF);
    printf("Received: %s\n", buffer);
    receivedNumber =  atoi(buffer);
    printf("Int value = %d\n", receivedNumber);

    close(fd);
  return 0;
}
