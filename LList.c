#include <stdlib.h>
#include <stdio.h>

struct node {
  char cargo;
  struct node *next
};

void print_list(struct node * n)
{
  printf("[");
  while (n->cargo) {
    printf("%c ", n->cargo);
    n = n->next;
  }
  printf("]\n");
}

struct node * insert_front(struct node * n, char c)
{
  n = n->next; // shift to the next node's pointer
  n = (struct node)malloc(sizeof(struct node)); // set that pointer to a new node
  n->cargo = c;
  return n; // this is the new front of the list
}
