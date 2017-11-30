#include <stdio.h>


int stringToInt(char c[]){
	int number = atoi(c);
	return number;	
}

int main(int argc, char *argv[]) {

  printf("%s\n", argv[0]);
  int gelenSayi = stringToInt(argv[0]);
  printf("%d\n", gelenSayi);

  return 0;
}
