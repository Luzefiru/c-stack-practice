#include "../include/stack.h"
#include <stdio.h>

int main(void) {
  puts("\nTesting a function defined in /src/stack/$(IMPLEMENTATION)/stack.c, included via stack.h");
  debugPrint();

  pop();

  puts("Press Any Key to Continue...");  
  getchar();    
}