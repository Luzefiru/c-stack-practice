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

/**
 * @brief Adds the specified element to the top of the stack.
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 * @param ch the element to add to the stack
 */
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

/**
 * @brief Removes the element at the top of the stack.
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 */
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

/**
 * @brief Returns the element at the top of the stack, otherwise ('\0') if the stack is empty.
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 * @return char 
 */
char top(Stack s) {
  // if list is empty, return '\0', else return topPtr's data
  return (s->topPtr == NULL) ? '\0' : s->topPtr->data;
}

/**
 * @brief Returns true (1) if the stack is empty, otherwise false (0).
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 * @return true 
 * @return false 
 */
bool isEmpty(Stack s) {
  // if list is empty, return true, else return false
  return s->topPtr == NULL;
}

/**
 * @brief Returns true (1) if the stack is full, otherwise false (0).
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 * @return true 
 * @return false 
 */
bool isFull(Stack s) {
  // if list is full, return true, else return false
  return s->length == MAX;
}

/**
 * @brief Returns a new instance of a Stack.
 * 
 * @return Stack 
 */
Stack init(void) {
  Stack newStack = (Stack) malloc(sizeof(Stack));

  if (newStack != NULL) {
    // initialize stack to NULL denoting an empty stack
	  newStack->topPtr = NULL;
	  newStack->length = 0;
  }

	return newStack;
}

/**
 * @brief Pretty prints the stack's elements, starting from the top-most element to the bottom.
 * 
 * @param s a pointer to the Stack object (struct Stack *)
 */
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
void debugPrint(void);

/**
 * @brief prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void){
  printf("\e[0;31m");
  puts("I'm in /src/stack/list/stack.c!\n");
  printf("\e[0m");
}















