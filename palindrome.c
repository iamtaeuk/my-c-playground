#include <stdio.h>
#include <string.h>

// To execute C, please define "int main()"

int main() {
    
    char *strus = "amanaplanacatahamayakayamahatacanalpanama";
    int length = strlen(strus);
    
    for (int i = 0; i < length; i++) {
        if (strus[i] != strus[length - i - 1]) {
            printf("bye\r\n");
            break;
        }
        if (i + 1 == length) {      //4 == 5
            printf("ok");
        }
    }
    
    
    
    
  return 0;
}
