#include <stdio.h>
#include <string.h>

// To execute C, please define "int main()"
int countHi(char* str);
int main() {

  printf("%d \n", countHi("xhixhi"));
  return 0;
}

// countHI("ahixhi") -> 1
// countHI("ahiasdsadhi") -> 2
// countHI("xhixhi") -> 0

int countHi(char* str){
  
  int count = 0;
  
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'x' && str[i + 1] == 'h' && str[i + 2] == 'i')
      i += 2;
    else if (str[i] == 'h' && str[i + 1] == 'i')
      count++;
    
  }
  
  return count;
}

