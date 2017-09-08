#include <stdio.h>

// To execute C, please define "int main()"

int main() {
  int ottawa = 145; // 00 01  24 - 
  
  // 1017 hr = 10, min = 17
  
  
  int victoria = 2400 - (300 - ottawa);
  int edmonton = 2400 - (200 - ottawa);
  int winnipeg = 2400 - (100 - ottawa);
  int toronto  = ottawa + 000;
  int halifax  = ottawa < 2300 ? ottawa + 100 : ottawa % 100;
  int stjohns  = ottawa < 2300 ? (ottawa + 130 < 59 ? ottawa + 130 : ottawa + 130 + (60 - ottawa % 100) ): (ottawa % 100) + 30 < 59 ? (ottawa % 100) + 30 : 100 + (ottawa % 100);
  
  printf("Ottawa: %d\n", ottawa);
  printf("%d %d %d %d %d %d\n", victoria, edmonton, winnipeg, toronto, halifax, stjohns);
  return 0;
}
