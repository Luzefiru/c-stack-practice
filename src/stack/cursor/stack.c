#include "../../../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10 // can change this, it's private

/* Heap Helper functions & types */
typedef struct node {
  char data;
  char next;
} Node;

typedef struct heap {
  Node elem[MAX];
  int avail;
} VirtualHeap;

int VirtualHeap__alloc(VirtualHeap *VH);
void VirtualHeap__free(VirtualHeap *VH, int index);

struct Stack {
  VirtualHeap *VH;
  int topIndex;
  int length;
};

typedef struct Stack * Stack;

void push(Stack s, char elem) {
  // allocate a new Node address
  int newNodeIndex = VirtualHeap__alloc(s->VH);

  if (newNodeIndex != -1) {
    s->VH->elem[newNodeIndex].next = s->topIndex;
    s->VH->elem[newNodeIndex].data = elem;
    
    // set the top element of the stack to newNodeIndex
    s->topIndex = newNodeIndex;
    // increment stack's length
    s->length++;
  }
}

void pop(Stack s) {
  if (s->topIndex != -1) {
    int tmp = s->topIndex;
    s->topIndex = s->VH->elem[s->topIndex].next;
    VirtualHeap__free(s->VH, tmp);

    s->length--;
  }
}

char top(Stack s) {
  char retval = '\0';

  if (s->topIndex != -1) {
    retval = s->VH->elem[s->topIndex].data;
  }

  return retval;
}

bool isEmpty(Stack s) {
  return (s->length == 0) ? true : false;
}

bool isFull(Stack s) {
  return (s->length == MAX) ? true : false;
}

Stack init(void) {
  Stack newStack = malloc(sizeof(Stack));
  newStack->VH = malloc(sizeof(VirtualHeap));

  // initialize VirtualHeap *
  int x;
  for (x = MAX - 1; x >= 0; x--) {
    newStack->VH->elem[x].next = x - 1;
  }
  newStack->VH->avail = MAX-1;

  // initialize stack to -1 denoting an empty stack
  newStack->topIndex = -1;
  // set length to 0
  newStack->length = 0;
}

void displayStack(Stack s) {
  int oldLength = s->length; // for pretty printing
  Stack buffer = init();

  puts("");
  while (s->topIndex != -1) {
    char tmp = top(s);
    pop(s);
    
    if (tmp != -1) {
      push(buffer, tmp);
      printf("|%3c%3c\n", tmp, '|');
    }
  }
  
  
  if (oldLength == 0) {
    puts("|     |");
  }
  puts("-------");

  // put back all elements to old stack
  while (buffer->topIndex != -1) {
    push(s, top(buffer));
    pop(buffer);
  }

  // delete buffer stack
  free(buffer->VH);
  free(buffer);
}

void makeNull(Stack s) {
  while (!isEmpty(s)) {
    pop(s);
  }
}

void insertBottom(Stack s, char elem) {
  if (length(s) + 1 <= MAX) {
    int oldLength = s->length; // for pretty printing
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
    free(buffer->VH);
    free(buffer);
  }
}

int length(Stack s) {
  return s->length;
}

/**
 * @brief prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void){
  printf("\e[0;32m");
  puts("I'm in /src/stack/cursor/stack.c!\n");
  printf("\e[0m");
}

/**
 * @brief allocates memory on a VirtualHeap and returns the index (address) of the allocated Node
 * 
 * @param VH the VirtualHeap
 * @return int 
 */
int VirtualHeap__alloc(VirtualHeap *VH) {
  int retval = -1;

  if (VH->avail != -1) {
    retval = VH->avail;
    VH->avail = VH->elem[VH->avail].next;
  }

  return retval;
}

/**
 * @brief Deallocates a target `index` in a VirtualHeap.
 * 
 * @param VH 
 * @param index 
 */
void VirtualHeap__free(VirtualHeap *VH, int index) {
  VH->elem[index].next = VH->avail;
  VH->avail = index;
}