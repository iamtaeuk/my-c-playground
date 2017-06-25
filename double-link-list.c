#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

typedef struct _node{
  int data;
  struct _node *prev;
  struct _node *next;
} *NODE;


typedef struct _list{
  NODE head;    
  NODE tail;
} List;



NODE allocNode (int data){
  NODE node = (NODE)malloc(sizeof(NODE));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void Initialize (List *lt){
  lt->head = NULL;
  lt->tail = NULL;
}

void Uninitialize (List *lt) {
  NODE temp = lt->head;
  free(lt->head);
  for (int i = 0; i < 5; i++){
  //  printf("%d\n",temp->data);
    temp = temp->next->next;
  //  printf("temp->prev: %d \n", temp->prev->data);
    temp->prev->data = 0;
    free(temp->prev);
  }
}

void Add (List *lt, int data){
  NODE node = allocNode(data);
  if (lt->head == NULL) {
    lt->head = lt->tail = node;
    lt->tail->prev = lt->head;
  } else if (lt->head == lt->tail) {
    node->prev = lt->head;
    lt->head->next = lt->tail;
    lt->tail = node;
  } else {
    lt->tail->prev->next = node;
    node->prev = lt->tail->prev;
    lt->tail = node;
  }
  
}


void Print(List *lt){
  NODE temp = lt->head;
  for(; temp == lt->tail ; temp = temp->next)
    printf("%d\n", temp->data);
}


int main(void) {
  
  List lt;
  Initialize(&lt);
  
  Add(&lt, 10);
  Add(&lt, 20);
  Add(&lt, 30);

  //Print(&lt);
  
  //printf("%d \n", lt.head->next->next->next->data);
  /*
  NODE one = lt.head;
  NODE two = lt.head->next;
  NODE three = lt.head->next->next;
  
  printf("before: %d %d %d \n", one->data, two->data, three->data);
  */
  //Uninitialize(&lt);

  
 // printf("\n\nAfter: %d %d %d \n", one->data, two->data, three->data);
  
  printf("30: %d \n", lt.tail->data);
  printf("20: %d \n", lt.tail->prev->data);
  printf("10: %d \n", lt.tail->prev->prev->data);
  return 0;
}
