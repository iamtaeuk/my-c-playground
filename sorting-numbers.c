#include <stdio.h>

int main() {
    
    int ls[999];
    int length = 10;
    
    int odd[999];
    int even[999];
    
    int oddController = 0;
    int evenController = 0;
    
    for (int i = 0; i < length; i++) {
        scanf("%d", &ls[i]);
        
        if (ls[i] % 2 != 0) {
            odd[oddController] = ls[i];
            oddController++;
        } else {
            even[evenController] = ls[i];
            evenController++;
        }
    }
    
    printf("----- ODD ----- \r\n");
    for (int i = 0; i < oddController; i++) {
        printf("%d\r\n", odd[i]);
    }
    printf("----- EVEN ----- \r\n");
    for (int i = 0; i < evenController; i++) {
        printf("%d\r\n", even[i]);
    }
    
    printf("---------------------------\r\n");
   
    for (int i = 0; i < oddController; i++) {
        printf(" %d ", odd[i]);
    }

    for (int i = 0; i < evenController; i++) {
        printf(" %d ", even[i]);
    }
    
    
    return 0;
}

// input) 
// 5

// 1
// 2
// 3
// 4
// 5



// Even:  20,10,30,6
// Odd:   11

//  Numbers: 1,  3,  5,  4,  2
