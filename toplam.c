#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void sendDateWithNamedPipe(char *number){
  int fd;
  char * myfifo = "/tmp/myfifo";
  /* create the FIFO (named pipe) */
  mkfifo(myfifo, 0666);
  fd = open(myfifo, O_WRONLY);
  /* write number to the FIFO but firstly convert int to charArray because function second param' takes a charArray*/
  write(fd, number, sizeof(number));
  //close(fd);
    /* remove the FIFO */
  //unlink(myfifo);
}

int main(int argc, char const *argv[]) {

  char n[3];
  char k[3];

  printf("n değerini giriniz:\n");
  fgets(n, 3, stdin);
  sendDateWithNamedPipe(n);
  printf("k değerini giriniz:\n");
  fgets(k, 3, stdin);
  sendDateWithNamedPipe(k);

  printf("islem bitti\n");

  return 0;
}
