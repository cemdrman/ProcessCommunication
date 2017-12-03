#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_BUF 1024

char *params[1];

void initializeParams(char c1[]){
	params[0] = c1;
}


int readFromNamedPipe() {
  int fdNamedPipe;
  char * myfifo = "/tmp/myfifo";
  char buffer[MAX_BUF];
  /* open, read, and display the message from the FIFO */
  fdNamedPipe = open(myfifo, O_RDONLY);
  read(fdNamedPipe, buffer, MAX_BUF);
  //close(fdNamedPipe);
  int receivedNumber = atoi(buffer);
  return receivedNumber;
}

int main(int argc, char const *argv[]) {

    int receivedN;
    int receivedK;

    receivedN =  readFromNamedPipe();
    printf("n = %d\n", receivedN);

    receivedK = readFromNamedPipe();
    printf("k = %d\n", receivedK);

    //---------

    int fd[2]; //for other writing and reading from small program as nkup
    pipe(fd);
    fd[0]; // for using read
    fd[1]; // for using write
    int f;
    int i;

  /*  f = fork();

    if (f == 0) {
      initializeParams("18");
      i = execv("nkup",params);
      perror("execv failed!");

      printf("Gönderildi\n");
    }else{
      wait(&i);
    }*/
  //
  return 0;
}
