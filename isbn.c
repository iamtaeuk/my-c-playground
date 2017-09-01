#include <stdio.h>

// To execute C, please define "int main()"

int main() {
  
  int isbn[13] = {9, 7, 8, 0, 9, 2, 1, 4, 1, 8};
  int fixedDigitCalc = 0;
  
  
  printf("Digit 10, 11, 12\n"); 
  scanf("%d", &*(isbn+10));
  scanf("%d", &*(isbn+11));
  scanf("%d", &*(isbn+12));

  for (int i = 0; i < (sizeof(isbn)/ sizeof(int)); i++)
    fixedDigitCalc = i % 2 == 0 ? isbn[i] * 1 + fixedDigitCalc : isbn[i] * 3 + fixedDigitCalc;
  
  printf("fdc: %d\n",fixedDigitCalc);
  
  
  return 0;
}
