#include <stdio.h>

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



int main() {
  
  /*
      head = n1 = (PADATA)malloc(sizeof(DATA));
      n1->data = 10;
      n1->link = NULL;
  */
  
  
  PDATA head = NULL, temp = NULL;
  
  for(int i = 10; i < 60; i = i + 10)
    head = insertNode(head, i);

  for(temp = head; temp ; temp = temp->link)
    printf("%d \n", temp->data);

  return 0;
}
