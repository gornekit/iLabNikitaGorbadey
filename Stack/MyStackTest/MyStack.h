#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 100
#define MAX_SIZE 10324440
#define ELEMENT_SIZE 104

typedef struct
{
    char str[LENGTH];
    int value;
} element_type;

typedef struct
{
    element_type * data;
    long long int size;
} stack_type;

enum VARIETY_ERRORS
{
    NO_POINTER,
    FULL_STACK,
    EMPTY_STACK,
    ERROR_NUMBER,
    NO_ERRORS,
};
typedef enum VARIETY_ERRORS VARIETY_ERRORS;

VARIETY_ERRORS stack_ctor(stack_type *stack);

VARIETY_ERRORS stack_push(stack_type *stack, element_type *element);

VARIETY_ERRORS stack_pop (stack_type *stack, element_type *element);

void stack_show (stack_type *stack);

VARIETY_ERRORS stack_pop_number (stack_type *stack, int *number, element_type *element);

VARIETY_ERRORS stack_push_number (stack_type *stack, long long int *number, element_type *element);

VARIETY_ERRORS stack_dctor(stack_type *stack);

#endif // MYSTACK_H
