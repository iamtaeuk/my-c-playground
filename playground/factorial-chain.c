#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// To execute C, please define "int main()"

int factorial(int input);
int factorialChain(int input);
int str2int(char* input);
void itoa(int num, char *str);


int main() {
    factorialChain(2512);
    return 0;
}

int factorial(int input) {
    int output = 1;
    for (int i = input; i > 0; i--) output *= i;
  
    return output;
}

int factorialChain(int input) {
    int division = 1;
    char int2str[20] = {0}; // heap location
    int length = strlen(int2str);
    int decrement = length;
    itoa(input, int2str);
    
   // printf("%d \n", str2int(numToStr[2]));
    
    
    
    
    for (int i = 0; i < length; i++) {
        
        while(decrement){
            division *= 10;
            decrement--;
        }
        printf("%d \n", atoi((int2str+i)) / division);
        
    }
    
    return 0;
}


int str2int(char* input) {

    printf("check character: %s\n", input);
    
    int output = 0;
    int multiplier = 1;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 48 && input[i] <= 57) {
            // DEBUG: printf(" = %d \n", strlen(input) - (i + 1));
            for (int j = 0; j < strlen(input) - (i + 1); j++) {
                multiplier *= 10;
            }
            output += (input[i] - 48) * multiplier;
            // DEBUG: printf("multiplier = %d \n", multiplier);
            multiplier = 1;
        } else {
            printf("Error! - NaN \n");
            output = 0;
            break;
        }
    }

    // DEBUG: printf("output = %d\r\n", output);

    return output;
}

/*
    char str[10];
    
    itoa(123, str);
    
    printf("%s %c\n", str, str[2]);
*/

void itoa(int num, char *str){ 
    int i=0; 
    int radix = 10;  // 진수 
    int deg=1; 
    int cnt = 0; 

    while(1){    // 자리수의 수를 뽑는다 
        if( (num/deg) > 0) 
            cnt++; 
        else 
            break; 
        deg *= radix; 
    } 
    deg /=radix;    // deg가 기존 자리수보다 한자리 높게 카운트 되어서 한번 나누어줌  
    // EX) 1241 ->    cnt = 4; deg = 1000; 
    for(i=0; i<cnt; i++)    {    // 자리수만큼 순회 
        *(str+i) = num/deg + '0';    // 가장 큰 자리수의 수부터 뽑음 
        num -= ((num/deg) * deg);        // 뽑은 자리수의 수를 없엠 
        deg /=radix;    // 자리수 줄임 
    } 
    *(str+i) = '\0';  // 문자열끝널..
}  






//  char *str = itoa(123);
//

// factorial(6)   6!   => 
// 4! = 4 * 3 * 2 * 1
// 6! = 6 * 5 * 4 * 3 * 2 * 1

//factorial chain

// 69                          5 factorial chains.

// 6! + 9! = 363600
// 3! + 6! + 3! + 6! + 0! + 0!
// 1454
// 169
// 363601
// 1454




// 1 ~ 1 000 000, n 60 factorial chains.........
