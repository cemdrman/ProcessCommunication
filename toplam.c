#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {

  int fd;
  char * myfifo = "/tmp/myfifo";

  /* create the FIFO (named pipe) */
  mkfifo(myfifo, 0666);
  /* write number to the FIFO but firstly convert int to charArray because function second param' takes a charArray*/
  char *number = "13";
  fd = open(myfifo, O_WRONLY);
  write(fd, number, sizeof(number));

  close(fd);

  /* remove the FIFO */
  unlink(myfifo);
  printf("islem bitti\n");


  return 0;
}
