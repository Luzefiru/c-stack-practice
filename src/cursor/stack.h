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

/**
 * @brief Adds the specified element to the top of the stack.
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 * @param ch the element to add to the stack
 */
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

/**
 * @brief Removes the element at the top of the stack.
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 */
void pop(Stack s) {
  if (s->topIndex != -1) {
    int tmp = s->topIndex;
    s->topIndex = s->VH->elem[s->topIndex].next;
    VirtualHeap__free(s->VH, tmp);

    s->length--;
  }
}

/**
 * @brief Returns the element at the top of the stack, otherwise ('\0') if the stack is empty.
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 * @return char 
 */
char top(Stack s) {
  char retval = '\0';

  if (s->topIndex != -1) {
    retval = s->VH->elem[s->topIndex].data;
  }

  return retval;
}

/**
 * @brief Returns true (1) if the stack is empty, otherwise false (0).
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 * @return true 
 * @return false 
 */
bool isEmpty(Stack s) {
  return (s->length == 0) ? true : false;
}

/**
 * @brief Returns true (1) if the stack is full, otherwise false (0).
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 * @return true 
 * @return false 
 */
bool isFull(Stack s) {
  return (s->length == MAX) ? true : false;
}

/**
 * @brief Returns a new instance of a Stack.
 * 
 * @return Stack 
 */
Stack init(void) {
  Stack newStack = (Stack) malloc(sizeof(Stack));
  newStack->VH = (VirtualHeap *) malloc(sizeof(VirtualHeap));

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

/**
 * @brief Pretty prints the stack's elements, starting from the top-most element to the bottom.
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 */
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

/**
 * @brief Returns the length of the stack
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 * @return int
*/
int length(Stack s) {
  return s->length;
}

/**
 * @brief Prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void){
  printf("\e[0;32m");
  puts("I'm in /src/stack/cursor/stack.h!\n");
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