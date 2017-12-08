#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUF 1024

void sendDataWithNamedPipe(char *number){
  int fd;
  char * myfifo = "/tmp/myfifo";
  /* create the FIFO (named pipe) */
  mkfifo(myfifo, 0666);
  fd = open(myfifo, O_WRONLY);
  /* write number to the FIFO but firstly convert int to charArray because function second param' takes a charArray*/
  write(fd, number, sizeof(number));
}

/**
*NamedPipe'dan data çekmek için yazılmıştır.
* Bilerek silinmedi!
*/
int readFromNamedPipe(){
  int fdNamedPipe;
  char * myfifo = "/tmp/myfifo";
  fdNamedPipe = open(myfifo, O_RDONLY);
  char bufferN[MAX_BUF];
  /* open, read, and display the message from the FIFO */
  read(fdNamedPipe, bufferN, MAX_BUF);
  return atoi(bufferN);
}

int main(int argc, char const *argv[]) {
  char n[3];
  char k[3];
  printf("n değerini giriniz:\n");
  fgets(n, 3, stdin);
  sendDataWithNamedPipe(n);
  printf("k değerini giriniz:\n");
  fgets(k, 3, stdin);
  sendDataWithNamedPipe(k);
/*  int i;
  int fark = k-n+1;
  int results[fark];
  for (i = 0; i <= fark; i++) {
      results[i] = readFromNamedPipe();
      int j;
      for (j = 0; j < i; j++) {
        printf("%d\n", results[i]);
      }
  }*/
  return 0;
}
