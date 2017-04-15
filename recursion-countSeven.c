#include <stdio.h>

// To execute C, please define "int main()"
int countSeven(int n);
int main() {

  printf("%d \n", countSeven(7));
  return 0;
}

// function countSeven(int n)
// countSeven(1377)         -> 2
// countSeven(7)            -> 1
// countSeven(132)          -> 0
// countSeven(77789456)     -> 3

int countSeven(int n){
  if (n == 0)
    return 0;
  else if (n % 10 == 7)
    return 1 + countSeven(n / 10);
  else
    return 0 + countSeven(n / 10);
}
