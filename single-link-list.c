#include <stdio.h>
#include <stdlib.h>

// To execute C, please define "int main()"


typedef struct _node{
  int data;
  struct _node *link;
}DATA, *PDATA;


PDATA nodeAlloc(int data){
  PDATA thing = (PDATA)malloc(sizeof(DATA));
  thing->data = data;
  thing->link = NULL;
  return thing;
}

PDATA insertNode(PDATA head, int data){
  PDATA n = nodeAlloc(data);
  if(head == NULL)
    return n;
  n->link = head;
  return n;
}

void printNode(PDATA p){
  printf("printNode: ------\n");
  for(; p ; p = p->link)
      printf("%d, ", p->data);
  printf("\n-----------------\n");
}

PDATA deleteNode(PDATA head, int data){
  PDATA copy = head;
  PDATA prevNode = head;
  for (;; copy = copy->link) {
    if (copy == NULL)
      break;
    
    if (copy->data == data) {
      prevNode->link = copy->link;
      free(copy);
      break;
    }
    
    prevNode = copy;
  }
  return head;
}

//         50 -> 40 -> 30 -> 20 -> 10 -> NULL
//         50 -> 40 -------------> 20 -> 10 -> NULL

int main() {
  
  PDATA head = NULL;
  
  for(int i = 10; i < 60; i = i + 10)
    head = insertNode(head, i);

  
  printNode(head);
  
  head = deleteNode(head, 30);
  head = deleteNode(head, 10);
  
  printf("\n");
  
  printNode(head);
  

  return 0;
}
