#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int factorial(int input);
int factorialChain(int input);
int historySearch (int find, int *from, int size);
void itoa(int num, char *str);

int main() {
    
    // 974322 has 60 factorial chains
   for (int i = 1; i <= 1000000; i++) 
        factorialChain(i);
    
    factorialChain(974322);
    
    return 0;
}

// n! = n * (n - 1) * (n - 2) * (n - 3) * .... * 1 
// int input => 1 ~ 9
int factorial(int input) {  
    int output = 1;
    for (int i = input; i > 0; i--) output *= i;
    
    return output;
}

int factorialChain(int input){ //1. 69 -> "69" -> a[0]  |   2. 69 -> (60/10 = 6) + 9
    int output = 0;
    int history[60] = {0}; // saves number from loops
    history[0] = input; // first history item is input, no more input

    
    //printf("garbage: %d \n" , history[59]);
    
    for (int i = 1; i < 61; i++) {
        // Converts 'history[n]' to String
        char tempStr[10] = {0};    
        itoa(history[i-1], tempStr);

        for (int j = 0; j < strlen(tempStr); j++) 
            history[i] += factorial(tempStr[j] - '0');

        // DEBUG: printf("i is %d and num is %d \n", i, history[i]);       
        if (historySearch(history[i], history, i - 1) == 1){
            //printf("Total of %d factorial chains in #%d \n", i, history[0]);
            
            if (history[59] > 0){
                printf("찾음 %d, #%d!!!!!!!!!!!!!!!!!!!!!!!\n", i, history[0]);
                break;
            } 
            
        }
    }

    return output;
}

int historySearch(int find, int *from, int position) {
    for (int i = 0; i < position; i++) {
        if (find == *(from + i)) 
            return 1;
    }
    
    return 0;
}

void itoa(int num, char *str){ 
    int i = 0, radix = 10, deg = 1, cnt = 0;
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

// 6! + 9! = 363600          =>  3! + 6! + 3! + 6! + 0! + 0! 
// 3! + 6! + 3! + 6! + 0! + 0!
// 1454
// 169
// 363601
// 1454




// 1 ~ 1 000 000, n 60 factorial chains.........
