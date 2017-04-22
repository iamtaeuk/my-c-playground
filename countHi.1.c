#include <stdio.h>
#include <string.h>

// To execute C, please define "int main()"
int countHi(char* str);
int main() {

  printf("%d \n", countHi("ghixhiahi"));
  return 0;
}

// countHI("ahixhi") -> 1
// countHI("ahiasdsadhi") -> 2
// countHI("xhixhi") -> 0

int countHi(char* str){
  
  int count = 0, h = 0, x = 0;
  
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'h') h = 1;
    if (str[i] == 'x') x = 1;
    
    if (str[i] == 'i' && h == 1 && x == 1) {
      h = 0;
      x = 0;
    }
    
    if (str[i] == 'i' && h == 1) {
      count++;
      h = 0;
      x = 0;
    }
    
  }
  
  return count;
}



