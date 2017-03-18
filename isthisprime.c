#include <stdio.h>

int isThisPrime(int input);

int main() {
    
    /* START TESTER */
    int count = 0;
    for (int i = 2; i < 100000; i++)
        if (isThisPrime(i) == 1)
            count += i;
    printf("%d", count);
    /* END TESTER */
    
    return 0;
}

int isThisPrime(int input) {
    for (int i = 2; i < input + 1; i++)
        if (input % i == 0 && input != i)
            return 0;
    return 1;
}
