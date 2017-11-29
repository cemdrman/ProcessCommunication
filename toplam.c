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


  //char **number = intToCharArray(13);
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


/*char **intToCharArray(int number){

  char **str[100];
  sprintf(str, "%d", number);
  // Now str contains the integer as characters
  return str;
}*/
