#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// To execute C, please define "int main()"
char* noX(char* str);int count = 0;

int main() {
  
  printf("%s \n", noX("AbxAb"));
  return 0;
}


// NO x

// noX("xaxb") ---> "ab"
// noX("abcdef") -> "abcdef"
// noX("xx") -> ""

char* noX(char* str) {
  if (*str == '\0') {
    return "";
  } else if (*(str) == 'x') {
    return noX((str + 1));
  } else {
    count++;
    char * new_str ;
    if((new_str = malloc(100)) != NULL){
        new_str[0] = '\0';   // ensures the memory is an empty string
        strcat(new_str, (str));
        strcat(new_str, noX(str + 1));
    }
    return new_str;
  }

}
