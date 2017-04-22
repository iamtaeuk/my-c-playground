#include <stdio.h>
#include <string.h>

// To execute C, please define "int main()"
int countHi(char* str);
int main() {

  printf("%d \n", countHi("ahixhi"));
  return 0;
}

// countHI("ahixhi") -> 1
// countHI("ahiasdsadhi") -> 2
// countHI("xhixhi") -> 0


int countHi(char* str){
  if (*str == '\0')
    return 0;
  else if (*(str) == 'x' && *(str + 1) == 'h' && *(str + 2) == 'i')
    return 0 + countHi(str + 3);
  // xhihihihi
  else if (*(str) == 'h' && *(str + 1) == 'i')
    return 1 + countHi(str + 2);
  else
    return 0 + countHi(str + 1);
}


//     [index + 1] --> *(str + 1)
//     \0
