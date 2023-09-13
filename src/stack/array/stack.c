#include "../../../include/stack.h"
#include <stdio.h>
#include <stdbool.h>
#define MAX 10 // can change this, it's private

struct Stack {
  // TODO: add your definitions here
};

typedef struct Stack * Stack;

// TODO: implement all of these
int push(Stack s, char elem);
char pop(Stack s);
char top(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
Stack init(void);
void displayStack(Stack s);

/**
 * @brief prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void){
  printf("\e[0;34m");
  puts("I'm in array-stack.c!\n");
  printf("\e[0m");
}