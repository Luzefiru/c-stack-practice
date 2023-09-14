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

void push(Stack s, char elem);
void pop(Stack s);
char top(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
Stack init(void);
void displayStack(Stack s);

void push(Stack s, char elem)
{
  if (s->top < MAX - 1)
  {
    s->data[++s->top] = elem;
  }
}

void pop(Stack s)
{
  if (s->top >= 0)
  {
    s->top--;
  }
}

char top(Stack s)
{
  return s->data[s->top];
}

bool isEmpty(Stack s)
{
  return s->top == -1;
}

bool isFull(Stack s)
{
  return s->top >= MAX - 1;
}

Stack init(void)
{
  Stack s = (Stack)malloc(sizeof(struct Stack));
  s->top = -1;
  return s;
}

void displayStack(Stack s)
{
  int x;
  for (x = s->top; x >= 0; x--)
  {
    printf("%c ", s->data[x]);
  }
  printf("\n");
}

int length(Stack s)
{
  return s->top + 1;
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
