#include "../../../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10 // can change this, it's private

struct Stack
{
  char data[MAX];
  int top;
};

typedef struct Stack *Stack;

// TODO: implement all of these
void push(Stack s, char elem);
void pop(Stack s);
char top(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
Stack init(void);
void displayStack(Stack s);

void push(Stack s, char elem)
{
  s->data[++s->top] = elem;
}

void pop(Stack s)
{
  s->data[s->top--];
}

char top(Stack s)
{
  return s->data[s->top];
}

bool isEmpty(Stack s)
{
  return s->top == 1;
}

bool isFull(Stack s)
{
  return s->top > MAX;
}

Stack init(void)
{
  Stack s = (Stack)malloc(sizeof(struct Stack));
  s->top = 1;
  return s;
}

void displayStack(Stack s)
{
  int x;
  for (x = s->top; x > 1; x--)
  {
    printf("%c ", s->data[x]);
  }
}

int length(Stack s) {
  int x;
  for (x = 0; x < s->top; x++) {}
  return x - 1;
}

/**
 * @brief prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void)
{
  printf("\e[0;34m");
  puts("I'm in /src/stack/array/stack.c!\n");
  printf("\e[0m");
}
