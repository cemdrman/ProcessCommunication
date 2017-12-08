#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  int receivedNumber;
  read(7, &receivedNumber, sizeof(int));
  int nKupPlus = receivedNumber + cbrt(receivedNumber);
  write(8, &nKupPlus, sizeof(int));
  return 0;
}
