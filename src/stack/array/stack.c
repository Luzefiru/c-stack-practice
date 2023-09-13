#include "../../../include/stack.h"
#include <stdio.h>
#include <stdbool.h>
#define MAX 10 // can change this

struct Stack {
  char Elem[10];
  int top;
};

typedef struct Stack * Stack;

/**
 * @brief adds the specified element to the top of the stack and returns the new length of the stack.
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @param ch the element to add to the stack
 * @return int
 */
int push(Stack s, char elem);

/**
 * @brief Removes the element at the top of the stack & returns it.
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @return char
 */
char pop(Stack s);

/**
 * @brief Returns the element at the top of the stack.
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @return char 
 */
char top(Stack s);

/**
 * @brief Returns true (1) if the stack is empty, otherwise false (0).
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @return true 
 * @return false 
 */
bool isEmpty(Stack s);

/**
 * @brief Returns true (1) if the stack is full, otherwise false (0).
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @return true 
 * @return false 
 */
bool isFull(Stack s);

/**
 * @brief Returns a new instance of a Stack
 * 
 * @return Stack 
 */
Stack init(void);

/**
 * @brief Pretty prints the stack's elements, starting from the top-most element to the bottom.
 * 
 * @param s a pointer to the Stack object (Stack *)
 */
void displayStack(Stack s);

/**
 * @brief prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void){
  printf("\e[0;34m");
  puts("I'm in array-stack.c!\n");
  printf("\e[0m");
}