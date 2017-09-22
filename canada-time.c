#include <stdio.h>

// To execute C, please define "int main()"

int main() {
  int ottawa = 50;
  
  // 1017 hr = 10, min = 17
  
  int hrs  = ottawa / 100;
  int min  = ottawa % 100;
                          
  int victoria = (hrs > 2 ? hrs - 3 : hrs + 24 - 3) * 100 + (min);
  int edmonton = (hrs > 1 ? hrs - 2 : hrs + 24 - 2) * 100 + (min);
  int winnipeg = (hrs > 0 ? hrs - 1 : hrs + 24 - 1) * 100 + (min);
  int toronto  = ottawa;
  int halifax  = (hrs < 24 - 1 ? hrs + 1 : hrs - 24 + 1) * 100 + (min);
  int stjohns  = (((min + 30) < 60) ? (((hrs < 24 - 1) ? ((hrs + 1) * 100) : ((hrs - 24 + 1) * 100 )) + (min + 30)) : (((hrs < 24 - 2) ? ((hrs + 2) * 100) : ((hrs - 24 + 2) * 100 )) + (min + 30 - 60)));
  
  printf("Ottawa: %d (%d:%d) \n", ottawa, hrs, min);
  printf("%d %d %d %d %d %d\n", victoria, edmonton, winnipeg, toronto, halifax, stjohns);
  
  return 0;
}
