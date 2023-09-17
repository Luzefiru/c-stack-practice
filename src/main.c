// change directory for different implementation: array | cursor | list 
// then run: make
#include "./list/stack.h" 
#include <stdio.h>

#define MAX 10

typedef struct Stack * Stack;

int main(void)
{
  puts("\nTesting a function defined in /src/stack/$(IMPLEMENTATION)/stack.c, included via stack.h");
  debugPrint();

  // /* test program */
  printf("\e[0;33m");
  puts("Stack s = init()");
  printf("\e[0m");
  Stack s = init();
  puts("");

  printf("\e[0;32m");
  puts("top(s)");
  printf("\e[0m");
  printf("> the element at the top of the stack = %c (integer value = %d)\n", top(s), top(s));
  puts("");

  printf("\e[0;31m");
  puts("isEmpty(s)");
  printf("\e[0m");
  isEmpty(s) ? puts("> true") : puts("> false");
  puts("");

  printf("\e[0;31m");
  puts("isFull(s)");
  printf("\e[0m");
  isFull(s) ? puts("> true") : puts("> false");
  puts("");

  printf("\e[0;36m");
  puts("push(s, 'U')");
  printf("\e[0m");
  push(s, 'U');
  printf("> new length of stack = %d\n", length(s));
  puts("");

  printf("\e[0;32m");
  puts("top(s)");
  printf("\e[0m");
  printf("> the element at the top of the stack = %c (integer value = %d)\n", top(s), top(s));
  puts("");

  printf("\e[0;36m");
  puts("push(s, 'A')");
  printf("\e[0m");
  push(s, 'A');
  printf("> new length of stack = %d\n", length(s));
  puts("");

  printf("\e[0;34m");
  puts("displayStack(s)");
  printf("\e[0m");
  displayStack(s);
  puts("");

  printf("\e[0;32m");
  puts("top(s)");
  printf("\e[0m");
  printf("> the element at the top of the stack = %c (integer value = %d)\n", top(s), top(s));
  puts("");

  printf("\e[0;35m");
  puts("pop(s)");
  printf("\e[0m");
  pop(s);
  puts("");

  printf("\e[0;32m");
  puts("top(s)");
  printf("\e[0m");
  printf("> the element at the top of the stack = %c (integer value = %d)\n", top(s), top(s));
  puts("");

  printf("\e[0;34m");
  puts("displayStack(s)");
  printf("\e[0m");
  displayStack(s);
  puts("");

  printf("\e[0;32m");
  puts("pushing: R I F E Z");
  printf("\e[0m");
  push(s, 'R');
  push(s, 'I');
  push(s, 'F');
  push(s, 'E');
  push(s, 'Z');
  printf("> new length of stack = %d\n", length(s));
  puts("");

  printf("\e[0;34m");
  puts("displayStack(s)");
  printf("\e[0m");
  displayStack(s);
  puts("");

  printf("\e[0;31m");
  puts("isFull(s)");
  printf("\e[0m");
  isFull(s) ? puts("> true") : puts("> false");
  puts("");

  printf("\e[0;36m");
  puts("push(s, 'X')");
  printf("\e[0m");
  push(s, 'X');
  
  printf("\e[0;36m");
  puts("push(s, 'X')");
  printf("\e[0m");
  push(s, 'X');

  printf("\e[0;36m");
  puts("push(s, 'X')");
  printf("\e[0m");
  push(s, 'X');

  printf("\e[0;36m");
  puts("push(s, 'X')");
  printf("\e[0m");
  push(s, 'X');

  printf("\e[0;36m");
  puts("push(s, 'X')");
  printf("\e[0m");
  push(s, 'X');

  printf("\e[0;36m");
  puts("push(s, 'X')");
  printf("\e[0m");
  push(s, 'X');
  puts("");

  printf("\e[0;34m");
  puts("displayStack(s)");
  printf("\e[0m");
  displayStack(s);
  printf("> new length of stack = %d\n", length(s));
  puts("");

  printf("\e[0;31m");
  puts("isFull(s)");
  printf("\e[0m");
  isFull(s) ? puts("> true") : puts("> false");
  puts("");

  puts("Popping all elements...\n");
  while (!isEmpty(s))
  {
    printf("\e[0;35m");
    puts("pop(s)");
    printf("\e[0m");
    pop(s);
  }
  puts("");

  printf("\e[0;34m");
  puts("displayStack(s)");
  printf("\e[0m");
  displayStack(s);
  puts("");

  printf("\e[0;31m");
  puts("isEmpty(s)");
  printf("\e[0m");
  isEmpty(s) ? puts("> true") : puts("> false");
  printf("> new length of stack = %d\n", length(s));
  puts("");

  puts("\nPress Any Key to Continue...");
  getchar();
}
