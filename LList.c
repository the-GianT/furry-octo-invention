#include <stdlib.h>
#include <stdio.h>

struct node {
  char cargo;
  struct node *next
};

// Precondition: The "next" pointer in the last node of the list must point to null
void print_list(struct node * front)
{
  printf("[");
  while (*front) {
    printf("%c ", front->cargo);
    front = front->next;
  }
  printf("]");
}

struct node * insert_front(struct node * front, char c)
{
  struct node * newNode = (struct node)malloc(sizeof(struct node));

  newNode->cargo = c;
  newNode->next = front;

  return newNode;
  
  /*
  front = front->next; // shift to the next node pointer
  front = (struct node)malloc(sizeof(struct node)); // create the new node
  
  front->cargo = c;
  front->next = &0;
  
  return front; // this is the new front of the list
  */
}

struct node * free_list(struct node * front)
{
  while (*front) {
    
  }
}
