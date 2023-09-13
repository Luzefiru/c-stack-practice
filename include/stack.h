#include <stdbool.h> // contains macro definitions for integers: true = 1, false = 0

#ifndef STACK_H
#define STACK_H

struct Stack;

/**
 * @brief adds the specified element to the top of the stack and returns the new length of the stack.
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @param ch the element to add to the stack
 * @return int
 */
int push(struct Stack s, char elem);

/**
 * @brief Removes the element at the top of the stack & returns it.
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @return char
 */
char pop(struct Stack s);

/**
 * @brief Returns the element at the top of the stack.
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @return char 
 */
char top(struct Stack s);

/**
 * @brief Returns true (1) if the stack is empty, otherwise false (0).
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @return true 
 * @return false 
 */
bool isEmpty(struct Stack s);

/**
 * @brief Returns true (1) if the stack is full, otherwise false (0).
 * 
 * @param s a pointer to the Stack object (Stack *)
 * @return true 
 * @return false 
 */
bool isFull(struct Stack s);

/**
 * @brief Returns a new instance of a Stack
 * 
 * @return Stack 
 */
struct Stack init(void);

/**
 * @brief Pretty prints the stack's elements, starting from the top-most element to the bottom.
 * 
 * @param s a pointer to the Stack object (Stack *)
 */
void displayStack(struct Stack s);

/**
 * @brief prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void);

#endif // STACK_H