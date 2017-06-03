#include <stdio.h>
#include <stdlib.h>

// To execute C, please define "int main()"


typedef struct _node{
  int data;
  struct _node *link;
}DATA, *PDATA;


PDATA nodeAlloc(int data){
  PDATA node = (PDATA)malloc(sizeof(DATA));
  node->data = data;
  node->link = NULL;
  return node;
}

PDATA insertNode(PDATA head, int data){
  PDATA node = nodeAlloc(data);
  if(head == NULL)
    return node;
  node->link = head;
  return node;
}

PDATA deleteNode(PDATA head, int data){
  PDATA copy = head;
  PDATA prevNode = head;
  for (;; copy = copy->link) {
    if (copy == NULL)
      break;
    
    if (copy->data == data) {
      if (prevNode->data != copy->data)
        prevNode->link = copy->link;
      else
        head = copy->link;
      free(copy);
      break;
    }
    
    prevNode = copy;
  }
  return head;
}

void printNode(PDATA node){
  printf("printNode: ------\n");
  for(; node ; node = node->link)
      printf("%d, ", node->data);
  printf("\n-----------------\n");
}

void push(PDATA *node, int data){
  *node = insertNode(*node, data);
}

int pop(PDATA *node){
  PDATA copy = *node;
  int dataToKill = copy->data;
  *node = deleteNode(*node, dataToKill);
  return dataToKill;
}

//         50 -> 40 -> 30 -> 20 -> 10 -> NULL
//         50 -> 40 -------------> 20 -> 10 -> NULL

int main() {
  
  PDATA head = NULL;
  
  push(&head, 100);
  push(&head, 200);
  push(&head, 300);
  push(&head, 400);


  printf("%d\n", pop(&head));  //300
  printf("%d\n", pop(&head));  //200
  printf("%d\n", pop(&head));  //100 
  printf("%d\n", pop(&head));  //100 
  printNode(head); 


  return 0;
}
