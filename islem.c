#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024

int readFromNamedPipe(){
  int fdNamedPipe;
  char * myfifo = "/tmp/myfifo";
  fdNamedPipe = open(myfifo, O_WRDONLY);
  char bufferN[MAX_BUF];
  /* open, read, and display the message from the FIFO */
  read(fdNamedPipe, bufferN, MAX_BUF);
  return atoi(bufferN);
}

int main() {

    int receivedN;
    int receivedK;
    receivedN = readFromNamedPipe(); // reading from pipe
    receivedK = readFromNamedPipe();
    //-----Calling sub programs----
    int pipefd[2]; //for other writing and reading from small program as a nkup
    int f;
    int i;
    int k;
    for ( k = receivedN; k <= receivedK; k++) {
      if (pipe(pipefd) < 0) { //creating pipe
         perror("has been throwing error while creating pipe");
         exit(1);
      }
      f = fork();
      if (f == 0) {
        write(6, &k, sizeof(int)); //writing to pipe
        i = execv("nkup",NULL);
        //close(pipefd[1]);
      }else{
        wait(&i); //waiting for child process
        int nKupResult;
        read(5, &nKupResult, sizeof(int)); //reading from pipe
        int pipefd1[2];
        int f1;
        int j;
        if (pipe(pipefd1) < 0) { //creating pipe
           perror("has been throwing error while creating pipe");
           exit(1);
        }
        f1 = fork();
        if (f1 == 0) {
          write(8,&nKupResult,sizeof(int));
          j = execv("nkupplus",NULL);
        }else{
          wait(&j);
          int result;
          read(7, &result, sizeof(int)); //reading from pipe
          printf("(%d ^ 3 + %d) = %d\n", k,k,result);
        }
      }
    }
  return 0;
}
