#include <stdlib.h>
#include <stdio.h>

struct node {
  char cargo;
  struct node *next;
};

// default constructor-ish thing
struct node * newNode0()
{
  struct node * new = (struct node *)malloc(sizeof(struct node *));
  new->cargo = 0;
  new->next = 0;

  return new;
}

// overloaded constructor-ish thing
struct node * newNode1(char c)
{
  struct node * new = (struct node *)malloc(sizeof(struct node *));
  new->cargo = c;
  new-> next = 0;

  return new;
}

// Precondition: The "next" pointer in the last node of the list must point to null
void print_list(struct node * front)
{
  printf("[");
  while (front) {
    printf("%c ", front->cargo);
    front = front->next;
  }
  printf("]"); // last element + closing bracket
}

struct node * insert_front(struct node * front, char c)
{
  struct node * newNode = (struct node *)malloc(sizeof(struct node *));

  newNode->cargo = c;
  newNode->next = front;

  return newNode; // This node is the new front of the list

  /*
  front = front->next; // shift to the next node pointer
  front = (struct node *)malloc(sizeof(struct node *)); // create the new node
  
  front->cargo = c;
  front->next = 0;
  
  return front; // this is the new front of the list
  */
}

struct node * free_list(struct node * front)
{
  struct node * tmp;
  while (front) {
    tmp = front;
    front = front->next;
    free(tmp);
  }
  free(front);
  return 0;
}

int main()
{
  struct node * mylist = newNode0();
  print_list(mylist);
  printf(" ...should be [ ]\n");
  free_list(mylist);

  struct node * yolist = newNode1('a');
  yolist = insert_front(yolist, 'b');
  yolist = insert_front(yolist, 'c');
  yolist = insert_front(yolist, 'd');
  print_list(yolist);
  printf(" ...should be [d c b a ]\n");
  free_list(yolist);
  
  return 0;
}
