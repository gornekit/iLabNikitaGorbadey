#include "MyStack.h"

int main()
{
    VARIETY_ERRORS Error = 4;
    stack_type stack;
    element_type element;
    long long int number = 0;
    long long int size = 0;

    stack_ctor(&stack);
    int i = 0;
    while (Error == 4)
  {
    element.str[0] = 'h';
    element.value = i%100;
    Error = stack_push(&stack, &element);
    if (i % 1000 == 0) printf("%s %d", stack.data[size].str, stack.data[size].value);
    ++i;
  }
    stack_show(&stack);
    printf("%d", Error);

    stack_dctor(&stack);

    return 0;

}
