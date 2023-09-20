#include "../../../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10 // can change this, it's private

typedef struct node {
  char data;
  struct node *next;
} *Node;

struct Stack {
  Node topPtr;
  int length;
};

typedef struct Stack * Stack;

// TODO: implement all of these
void push(Stack s, char elem);
void pop(Stack s);
char top(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
Stack init(void);
void displayStack(Stack s);
int length(Stack s);

/**
 * @brief prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void){
  printf("\e[0;31m");
  puts("I'm in /src/stack/list/stack.c!\n");
  printf("\e[0m");
}

void push(Stack s, char elem) {
  // checks if there is available space to insert
  if (s->length < MAX) {
    Node newNode = (Node)malloc(sizeof(struct node));

    if (newNode != NULL) {
      newNode->data = elem;

      // set the link of newNode to the topPtr
      newNode->next = s->topPtr;
      // set topPtr to newNode
      s->topPtr = newNode;
    }

    s->length++;
  }
}

void pop(Stack s) {
  // checks if there is a node to delete
  if (s->topPtr != NULL) {
    // initialize temp to topPtr
    Node temp = s->topPtr;
    // set topPtr to topPtr link
    s->topPtr = s->topPtr->next;
    // dealloctes temp
    free(temp);
    
    s->length--;
  }
}

char top(Stack s) {
  // if list is empty, return '\0', else return topPtr's data
  return (s->topPtr == NULL) ? '\0' : s->topPtr->data;
}

bool isEmpty(Stack s) {
  // if list is empty, return true, else return false
  return s->topPtr == NULL;
}

bool isFull(Stack s) {
  // if list is full, return true, else return false
  return s->length == MAX;
}

Stack init(void) {
  Stack newStack = malloc(sizeof(Stack));

  if (newStack != NULL) {
    // initialize stack to NULL denoting an empty stack
	  newStack->topPtr = NULL;
	  newStack->length = 0;
  }

	return newStack;
}

void displayStack(Stack s) {
  Node trav;

  puts("");
  for (trav = s->topPtr; trav != NULL; trav = trav->next) {
    printf("|%3c%3c\n", trav->data, '|');
  }
  
  if (s->length == 0) {
    puts("|     |");
  }
  puts("-------");
}

void makeNull(Stack s) {
  while (!isEmpty(s)) {
    pop(s);
  }
}

void insertBottom(Stack s, char elem) {
  if (!isFull(s)) {
    Stack buffer = init();

    while (!isEmpty(s)) {
      push(buffer, top(s));
      pop(s);
    }

    push(buffer, elem);

    // put back all elements to old stack
    while (!isEmpty(buffer)) {
      push(s, top(buffer));
      pop(buffer);
    }

    // delete buffer stack
    free(buffer);
  }
}

int length(Stack s) {
  return s->length;
}