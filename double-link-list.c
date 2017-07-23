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
  NODE current;
  
} List;



NODE allocNode (int data){
  NODE node = (NODE)malloc(sizeof(NODE));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void Initialize (List *lt){

  lt->head = allocNode(0);
  lt->tail = allocNode(0);
  lt->head->next = lt->tail;
  lt->tail->prev = lt->head;
  
}

void Uninitialize (List *lt) {
  NODE temp = lt->head->next; 
  while (TRUE){
    free(temp->prev);
    temp = temp->next;
    
    if (temp->next == NULL){
      free(temp->prev);
      free(temp);
      break;
    }
  }
}

void Add (List *lt, int data){
  NODE node = allocNode(data);
  lt->tail->prev->next = node;
  node->prev = lt->tail->prev;
  lt->tail->prev = node;
  node->next = lt->tail;
}


void Reset(List* lt){
  lt->current = lt->head->next;  
}

int GetItem(List* lt){
  return lt->current->data;
}

void Next(List *lt){
  lt->current = lt->current->next;
}

int HasNext(List *lt){
  return lt->current == lt->tail ? 0 : 1;
}

void Insert(List* lt, int data){
  NODE node = allocNode(data);
  lt->current->prev->next = node;
  node->prev = lt->current->prev;
  lt->current->prev = node;
  node->next = lt->current;
  lt->current = node->prev;
}

void Remove(List *lt){
  lt->current->prev->next = lt->current->next;
  lt->current->next->prev = lt->current->prev;
  free(lt->current);
  Reset(lt);
}


void Print(List *lt) {

  // Next Time

  NODE temp = lt->head;
  for (;; temp = temp->next) {
    printf("%d: %d & %p\n", temp->data, temp->data, temp);
    if (temp->next == NULL)
      break;
  }
}


int main(void) {

  List lt;
  Initialize(&lt);

  Add(&lt, 10);
  Add(&lt, 20);
  Add(&lt, 30);
  Add(&lt, 40);
  Add(&lt, 50);
  Add(&lt, 60);
  Add(&lt, 70);

  // approach current data at 20
  for(Reset(&lt); HasNext(&lt); Next(&lt)){
    if(20 == GetItem(&lt))
      break;
  }
    Insert(&lt, 90);
    Print(&lt);
  
  // approach current data at 90
    for(Reset(&lt); HasNext(&lt); Next(&lt)){
    if(90 == GetItem(&lt))
      break;
  }
    Remove(&lt);
    Print(&lt);
  
  
 // lt->current = lt->tail->prev;
 // printf("HasNext: %d \n", HasNext(&lt));

  //printf("%d \n", lt.head->next->next->next->data);
  /*
  NODE one = lt.head;
  NODE two = lt.head->next;
  NODE three = lt.head->next->next;

  printf("before: %d %d %d \n", one->data, two->data, three->data);
  */
  //Uninitialize(&lt);
  
  //Print(&lt);

 // printf("\n\nAfter: %d %d %d \n", one->data, two->data, three->data);

  /*

  printf("50: %d \n", lt.tail->data);
  printf("50: %d \n", lt.tail->prev->data);
  printf("50: %d \n", lt.tail->prev->prev->data);
  printf("40: %d \n", lt.tail->prev->prev->prev->data);
  printf("30: %d \n", lt.tail->prev->prev->prev->prev->data);
  printf("20: %d \n", lt.tail->prev->prev->prev->prev->prev->data);
  printf("10: %d \n", lt.tail->prev->prev->prev->prev->prev->prev->data);

  */
  return 0;
}
