#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int data;
  struct _node *prev;
  struct _node *next;

} *NODE;

NODE allocNode(int data){
  NODE node = (NODE)malloc(sizeof(NODE));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}





int main() {
  

  NODE head = NULL;
  NODE tail = NULL;
  NODE temp = NULL;

  head = allocNode(10);
  temp = allocNode(20);
  tail = allocNode(30);
  
  head->next = temp->data;
  temp->prev = head->data;
  temp->next = tail->data;
  tail->prev = temp->data;
  
  
  
  
  printf("%d \n", head->data);              //10
  printf("%d \n", head->next->data);        //20
  printf("%d \n", head->next->next->data);  //30
  
  
  //free();
  //free();
  //free();
  
  // NULL <- 10 <-> 20 <-> 30 -> NULL
  return 0;
}
