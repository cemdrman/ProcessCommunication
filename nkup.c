#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int receivedNumber;
  read(5, &receivedNumber, sizeof(int));
  int nKup = receivedNumber * receivedNumber * receivedNumber;
  write(6, &nKup, sizeof(int));
  return 0;
}
