#ifndef CALCULATE_H
#define CALCULATE_H

#include "MyStack.h"

enum CALC_ERR
{
	STACK_NO_POINTER,
	STACK_FULL_STACK,
	STACK_EMPTY_STACK,
	STACK_ERROR_NUMBER,
	CALC_NO_ERR,
	DEVIDE_ERR,
	POW_ERR,
	NO_OPERATOR,
	COMAND_ERR,
	FILE_ERR,
	EXPRESSION_ERR	
};

CALC_ERR calOperation (const char operat, stack_type * stack);

CALC_ERR calculator (FILE * file, element_type * answer);

void writeErr (CALC_ERR error);

#endif //CALCULATE_H
