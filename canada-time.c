#include <stdio.h>

// To execute C, please define "int main()"

int main() {
  int ottawa = 2300; // 00 01  24 - 
  
  // 1017 hr = 10, min = 17
  
  int hrs  = ottawa / 100;
  int min  = ottawa % 100;
  
  int victoria =  (((hrs - 3) * 100) > 0 ? ((hrs - 3) * 100) : 2400 - (3 * 100))+ min; // Ottawa -3 ; 2345
  int edmonton =  (((hrs - 2) * 100) > 0 ? ((hrs - 2) * 100) : 2400 - (2 * 100))+ min;
  int winnipeg =  (((hrs - 1) * 100) > 0 ? ((hrs - 1) * 100) : 2400 - (1 * 100))+ min;
  int toronto  =  (((hrs - 0) >  0 ? (hrs - 0) : ((24 - hrs) < 24 ? (24 - hrs) : 0) - 0) * 100) + min; // Toronto = Ottawa
  int halifax  =  (((hrs + 1) < 23 ? (hrs + 1) : 0) * 100) + min;
  int stjohns  =  (min + 30) > 60 ? 100 + (min - 30) : ((hrs + 1) < 23 ? (hrs + 1) : 1) * 100 + (min + 30);
  
  printf("Ottawa: %d (%d:%d) \n", ottawa, hrs, min);
  printf("%d %d %d %d %d %d\n", victoria, edmonton, winnipeg, toronto, halifax, stjohns);
  
  return 0;
}
