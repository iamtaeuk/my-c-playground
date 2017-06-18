#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int data;
  struct _node *prev;
  struct _node *next;
} *NODE;


typedef struct _list{
  NODE head;    
  NODE tail;
} List;



NODE allocNode(int data){
  NODE node = (NODE)malloc(sizeof(NODE));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void Initialize(List *lt){
  lt->head = NULL;
  lt->tail = NULL;
}

void Add(List *lt, int data){
  NODE node = allocNode(data);
  if (lt->head == NULL) {
    lt->head = lt->tail = node;
    lt->head->next = lt->tail;
    lt->tail->prev = lt->head;
  } else {
    node->next = lt->tail;
    node->prev = lt->tail->prev;
    lt->tail->prev = node;
    lt->tail->prev->prev->next = node;
  }
  
}

int main() {
  
  List lt;
  Initialize(&lt);
  
  Add(&lt, 10);
  Add(&lt, 20);
  Add(&lt, 30);
  printf("%d \n", lt.head->data);
  
  return 0;
}
