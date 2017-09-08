#include <stdio.h>

// To execute C, please define "int main()"

int main() {
  int bt = 1;
  int np = 1;
  int yp = 1;
  int limit = 6;
  
  int count = 0;
  
  for (int i = 0; i <= limit; i++){
    for (int j = 0; j <= limit; j++){
      for (int k = 0; k <= limit; k++){
        if (i*bt + j*np + k*yp <= limit && i + j + k > 0) {
          printf("%d %d %d \n", i, j, k);
          count++;
        }
      }
    }
  }
  
  printf("Number of ways: %d\n", count);
  return 0;
}
