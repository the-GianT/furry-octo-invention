#include <stdlib.h>
#include <stdio.h>

struct node {
  char c;
  struct node *next
};

void print_list(struct node * n)
{
  printf("[");
  while (n->c) {
    printf("%c ", n->c);
    n = n->next;
  }
  printf("]\n");
}
