#include "../include/stack.h"
#include <stdio.h>

#define MAX 10

struct Stack
{
  char data[MAX];
  int top;
};

typedef struct Stack * Stack;

int main(void)
{
  puts("\nTesting a function defined in /src/stack/$(IMPLEMENTATION)/stack.c, included via stack.h");
  debugPrint();

  // /* test program */
  puts("Stack s = init()");
  Stack s = init();
  puts("");

  puts("top(s)");
  printf("> the element at the top of the stack = %c (integer value = %d)\n", top(s), top(s));
  puts("");

  puts("isEmpty(s)");
  isEmpty(s) ? puts("> true") : puts("> false");
  puts("");

  puts("isFull(s)");
  isFull(s) ? puts("> true") : puts("> false");
  puts("");

  puts("push(s, 'U')");
  push(s, 'U');
  printf("> new length of stack = %d\n", length(s));
  puts("");

  puts("top(s)");
  printf("> the element at the top of the stack = %c (integer value = %d)\n", top(s), top(s));
  puts("");

  puts("push(s, 'A')");
  push(s, 'A');
  printf("> new length of stack = %d\n", length(s));
  puts("");

  puts("displayStack(s)");
  printf("> ");
  displayStack(s);
  puts("");

  puts("top(s)");
  printf("> the element at the top of the stack = %c (integer value = %d)\n", top(s), top(s));
  puts("");

  puts("pop(s)");
  pop(s);
  puts("");

  puts("top(s)");
  printf("> the element at the top of the stack = %c (integer value = %d)\n", top(s), top(s));
  puts("");

  puts("displayStack(s)");
  displayStack(s);
  puts("");

  puts("pushing: R I F E Z");
  push(s, 'R');
  push(s, 'I');
  push(s, 'F');
  push(s, 'E');
  push(s, 'Z');
  printf("> new length of stack = %d\n", length(s));
  puts("");

  puts("displayStack(s)");
  printf("> ");
  displayStack(s);
  puts("");

  puts("isFull(s)");
  isFull(s) ? puts("> true") : puts("> false");
  puts("");

  puts("push(s, 'X')");
  push(s, 'X');
  puts("");

  puts("push(s, 'X')");
  push(s, 'X');
  puts("");

  puts("push(s, 'X')");
  push(s, 'X');
  puts("");

  puts("push(s, 'X')");
  push(s, 'X');
  puts("");

  puts("push(s, 'X')");
  push(s, 'X');
  puts("");

  puts("push(s, 'X')");
  push(s, 'X');
  puts("");

  puts("displayStack(s)");
  printf("> ");
  displayStack(s);
  printf("> new length of stack = %d\n", length(s));
  puts("");

  puts("isFull(s)");
  isFull(s) ? puts("> true") : puts("> false");
  puts("");

  puts("Popping all elements...\n");
  while (!isEmpty(s))
  {
    puts("pop(s)");
    pop(s);
    puts("");
  }

  puts("displayStack(s)");
  printf("> ");
  displayStack(s);
  puts("");

  puts("isEmpty(s)");
  isEmpty(s) ? puts("> true") : puts("> false");
  printf("> new length of stack = %d\n", length(s));
  puts("");

  puts("\nPress Any Key to Continue...");
  getchar();
}
