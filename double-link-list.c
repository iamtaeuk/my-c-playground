#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void AddHead(List *lt, int data){
  NODE node = allocNode(data);
  lt->head->next->prev = node;
  node->next = lt->head->next;
  lt->head->next = node;
  node->prev = lt->head;
  lt->current = node;
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

void RemoveHead(List *lt){
  NODE headToRemove = lt->head->next;
  lt->head->next = lt->head->next->next;
  lt->head->next->prev = lt->head;
  Reset(lt);
  free(headToRemove);
}

void RemoveTail(List *lt){
  NODE tailToRemove = lt->tail->prev;
  lt->tail->prev = lt->tail->prev->prev;
  lt->tail->prev->next = lt->tail;
  Reset(lt);
  free(tailToRemove);
}

void SeqSearch(List *lt, int data){
  NODE temp = lt->head;
  for (int i = -1;; temp = temp->next, i++) {
    if (temp->data == data)
      printf(" [%d]:%d \n", i, data);
    if (temp->next == NULL)
      break;
  }
}

void Print(List *lt) {
  NODE temp = lt->head;
  for (;; temp = temp->next) {
    printf("%d: %d & %p\n", temp->data, temp->data, temp);
    if (temp->next == NULL)
      break;
  }
}

void GenRandomNum(int *arr, int size, int range){
  srand(time(NULL));
  int num = 0;
  for (int i = 0; i < size; i++){
    RAND:
    num = rand() % range + 1;
    // num = (rand() % (max + 1 - min)) + min
    for (int j = 0; j < size; j++)
      if(arr[j] == num)
        goto RAND;
    arr[i] = num;
  }
}

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}


void BubbleSort(int *arr, int size){
  for (int i = size; i > 0; i--){
    for (int j = 0; j < size - 1; j++){
      if(arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
      } else if (arr[j+1] == "\0"){
        continue;
      }
    }
  }
}

int main(void) {

  List lt;
  Initialize(&lt);

  int SIZE = 60;
  
  int arr[SIZE];
    
  GenRandomNum(arr, SIZE, SIZE * 2);
  BubbleSort(arr, SIZE);

  for (int i = 0; i < SIZE; i++)
    Add(&lt, arr[i]);
  
  Print(&lt);
  
  
  return 0;
}
