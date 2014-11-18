#include "MyStack.h"

VARIETY_ERRORS stack_ctor(stack_type *stack)
{
    if (stack == NULL)
        return NO_POINTER;

    stack->data=NULL;
    stack->size=0;

    return NO_ERRORS;
}

VARIETY_ERRORS stack_push (stack_type *stack, element_type *element)
{
    if (stack == NULL || element == NULL)
        return NO_POINTER;

   if (stack->size > MAX_SIZE/ELEMENT_SIZE )
    return FULL_STACK;

     stack->data = (element_type *) realloc (stack->data , (stack->size + 1) * sizeof (element_type));
     stack->data[stack->size] = *element;
     stack->size++;

   return NO_ERRORS;

};

VARIETY_ERRORS stack_pop (stack_type *stack, element_type *element)
{
    if (stack == NULL || element == NULL)
        return NO_POINTER;

    if (stack->size == 0)
        return EMPTY_STACK;

    *element = stack->data[stack->size - 1];
    stack->data = (element_type *) realloc (stack->data, (stack->size -1) * sizeof (element_type));
    stack->size--;

    return NO_ERRORS;
};

VARIETY_ERRORS stack_push_number (stack_type *stack, long long int *number , element_type *element)
{
    if (stack == NULL || element == NULL || number == NULL)
        return NO_POINTER;

    if (stack->size > MAX_SIZE/ELEMENT_SIZE )
        return FULL_STACK;

    if (*number < 0 || *number > stack->size)
        return ERROR_NUMBER;

    stack->data = (element_type *) realloc (stack->data, (stack->size +1) *sizeof (element_type));
    for (int i = stack->size ; i>(*number - 1) ; --i)
        stack->data[i] = stack->data[i-1] ;
    stack->data[*number - 1] = *element ;
    stack->size++;

    return NO_ERRORS;
};

VARIETY_ERRORS stack_pop_number (stack_type *stack, int *number, element_type *element)
 {
    if (stack == NULL || element == NULL)
        return NO_POINTER;

    if (stack->size == 0)
        return EMPTY_STACK;

    if (*number < 0 || *number > stack->size)
        return ERROR_NUMBER;

    *element = stack->data[*number-1];
    for (int i = *number-1 ; i<stack->size -1 ; ++i)
        stack->data[i] = stack->data[i+1];

    stack->data = (element_type *) realloc (stack->data, (stack->size -1) * sizeof (element_type));
    stack->size--;

    return NO_ERRORS;
};

/*void stack_show (stack_type *stack)
{
    int i = 0;
    for (i = 0; i < stack->size; ++i)
    {
        printf("%d ", i+1);
        printf("%s\n", stack->data[i].str);
        printf("  %d\n", stack->data[i].value);
    }
};*/

VARIETY_ERRORS stack_dctor(stack_type *stack)
{
    if (stack == NULL)
        return NO_POINTER;

     free (stack->data);
     stack->size = 0;

     return NO_ERRORS;
};

