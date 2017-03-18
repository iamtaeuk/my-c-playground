#include <stdio.h>
int factorial(int input);

int main() {
  printf("%d \n", factorial(8));
  return 0;
}

int factorial(int input) {
  int output = 1;
  for (int i = input; i > 0; i--) output *= i;
  
  return output;
}

// factorial(6)   6!   => 
// 4! = 4 * 3 * 2 * 1
// 6! = 6 * 5 * 4 * 3 * 2 * 1
