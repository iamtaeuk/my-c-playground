#include <stdio.h>
#include <string.h>

int str2int();

int main() {
    
    str2int("987654321");     // '1', '2', '3', '4'
    
    return 0;
    
}

("87324a347983")

"Not a number"


int str2int(char* input) {
    
    int output = 0;
    int multiplier = 1;
    
    for (int j = 0; j < strlen(input); j++) {
        
    }
    
    /*
    
    for (int j = 0; j < strlen(input); j++) {
        if (input[j] >= 48 && input[j] <= 57) {
            
            if (j != 0) {
                
                for (int k = 0; k < j; k++) {
                    multiplier *= ;
                    //printf("multiplier is %d\n", multiplier);
                }
            
                output += (multiplier * (input[j] - 48));
                multiplier = 1;
            } else {
                output = input[j] - 48;
            }            
            
        }        
    }
    */
    
    /* 
    for (int j = 0; j < strlen(input); j++) {
        if (input[j] >= 48 && input[j] <= 57) {
            
            for (int k = 0; k < j; k++) multiplier *= 10;
            output += multiplier * (input[j] - 48);
            
        }        
    }
    
    */
    /*
    for (int j = strlen(input); j >= 0; j--) {
        if (input[j] >= 48 && input[j] <= 57) {
            
            for (int k = j; k >= 0; k--) multiplier *= 10;
            printf("multiplier is %d\n", multiplier);
            output += multiplier * (input[j] - 48);

            
        }        
    }
    */
    
    printf("output = %d\r\n", output);
    
    return 1;
}

//    convert string number to integer        "5" + "1" =  "51"
//     '1' -> 49 - 48   ==> 1       - '0', - 48
//     '4' -> 52 - 48  ===> 4
