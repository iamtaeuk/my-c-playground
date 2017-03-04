#include <stdio.h>
#include <stdlib.h>

void swap (int *asdf, int *uuu){
    int temp = *asdf;
    *asdf = *uuu;
    *uuu = temp;
    
 
}

int main() {
    
     /*
  int one = 3;
  int two = 5;
  
  int *first = malloc(4);        // malloc(sizeof(int));
  int *second = malloc(4);
  
  *first = one;
  *second = two;
  
  int result = *first + *second;
  
  printf("%p %p \n", first, second);
  printf("%d\r\n", result);
    
  free(first);
  free(second);
  
  printf("%p %p \n", first, second);
    
  *first = 1234;
  *second = 6;
  
  printf("%d, %d\r\n", *first, *second);
    

input)

number: 3
number: 5
operator: +

output)
8

*/

  
    /*
 
    int a = 100;
    int b = 200;
     
    
    printf("%d %d\n", a , b);
    
    swap(&a , &b);
    
    printf("after: %d %d\n", a , b);  
    
    
    
    
    int *address = (int*)malloc(10000004);
    
    
    *address = 4; <== 주가 가르키고 있는 곳.
    address <== 주소 값
    
    if (*address == 4){

        
        printf("%p\n", address);
        free(address);
    
    }else{
    
        printf("Not enough space! \n");
    }
    
    
    */
    
    int arry[100] = {0};
    
    
    printf("%p \n", arry);
    
    printf("%d \n", arry[0]);
    arry[0] = 200;
    printf("index: %d \n", arry[0]);
    
    printf("pointer: %d \n", *arry);
    
    *(arry + 1) = 500;
    printf("pointer: %d \n", *(arry + 1));
    printf("%p \n", arry + 1);

    
  return 0;
}
