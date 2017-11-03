#include <stdio.h>
#include <string.h>


int main() {

  char input[99999] = "3M1D2C"; // {'3', 'M', '1', 'D',....}
  char  r[7]  =   {'I' , 'V' , 'X' , 'L' , 'C' , 'D' ,  'M' }; // or = "IVXLCDM"
  int r2a[7]  =   { 1  ,  5  ,  10 , 50  , 100 , 500 , 1000 };
  
  // result += (input[i-1] - '0') * 숫자임;
  int indexNum = 0;
  int result = 0;
  
  for (int i = 0; i < strlen(input); i++) {
    if (i != 0) {
      indexNum = 0;
      
      for (indexNum = 0; indexNum < 7; indexNum++) {
        if (input[i] == r[indexNum]) {
          break;
        }
      }
      
      if (input[i-2] == r2a[indexNum-1] || input[i-2] == r2a[indexNum+1]) {
        if (i % 2 != 0) result += (input[i-1] - '0') * r2a[indexNum];
      }
    }
  } 
  
  printf("%d \r\n", result);
    
  return 0;
}



// int a = '3' - '0';


// Aromatic Number
/*
0,1,2,3,4,5,6,7,8,9,10,11,12
    
    Arabic Digits
    
Roman Numerals

            I,   V,    X,    L,     C,     D,     M
            1    5    10    50    100    500    1000

    
   input)
    
    
    3M1D2C
    
    3*(1000) + 1*(500) + 2*(100) 
    
    
    output)
    3700
    
    

    input)
    
    3X2I4X
    
    
    3*(10) - 2*(1) + 4(10)
    
    output)
    68
    
    */
    
