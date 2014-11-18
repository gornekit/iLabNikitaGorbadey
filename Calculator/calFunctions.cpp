#include "Calculate.h"

CALC_ERR calOperation(const char operat , stack_type * stack )
{
	double pop_1 = 0 ,  pop_2 = 0;
	CALC_ERR error = CALC_NO_ERR;
	error = (CALC_ERR) stack_pop (stack ,& pop_1);
	error = (CALC_ERR) stack_pop (stack ,& pop_2);
	if (error != CALC_NO_ERR)
		return error;

	switch(operat)
	{
		case '+' : 
			pop_1 = pop_1 + pop_2;
			break;
		case '-' :
			pop_1 = pop_2 - pop_1;
			break;
		case '*' :
			pop_1 = pop_1 * pop_2;
			break;
		case '/' :
			if (pop_1 == 0)
					error =  DEVIDE_ERR;
			pop_1 = pop_2 / pop_1;
			break;
		case '^' :
			if (pop_2<0 && pop_1<1 && pop_1 > -1)
					error = POW_ERR;
			pop_1 = pow(pop_2 , pop_1);
			break;
		default :
			error =  NO_OPERATOR;
			break;
		}
	error = (CALC_ERR) stack_push (stack , &pop_1);

	return error;
};

CALC_ERR calculator (FILE * file , double * answer)
{
	stack_type stack;
	CALC_ERR error = (CALC_ERR) stack_ctor(&stack);
	int tmp = getc(file);
	double value = 0;
	while (tmp != EOF)
	{
		if (tmp >= '0' && tmp <= '9')
			{
				ungetc(tmp , file);
				fscanf(file , "%lg" , &value);
				error = (CALC_ERR) stack_push(&stack , &value);
			}
		else
			{
				if (tmp == '-')
					{
						int next = getc(file);
						if (next == ' ')
							error = calOperation(tmp , &stack);
						else
							{
								ungetc(next , file);
								ungetc(tmp , file);
								fscanf(file , "%lg" , &value);
								error = (CALC_ERR) stack_push(&stack , &value);
							}
					}
				if (tmp !='\n' && tmp != ' ' && tmp != '-')
					error = calOperation(tmp , &stack);

			}
		if (error != CALC_NO_ERR)
			return error;
		
		tmp = getc(file);
	}
	
	error = (CALC_ERR) stack_pop (&stack , answer);

	if (stack.size != 0)
		{
			error = EXPRESSION_ERR;
			return error;
		}

	if (error != CALC_NO_ERR) 
		return error;
	
	stack_dctor(&stack);
	return CALC_NO_ERR;
};

void writeErr (CALC_ERR  error)
{
		switch(error)
		{
			case 0 :
				fprintf(stderr , "Error stack creation\n");
				break;
			case 1 :
				fprintf(stderr , "Stack is full\n");
				break;
			case 2 :
				fprintf(stderr , "Stack is empty\n");
				break;
			case 5 :
				fprintf(stderr , "You've devided on zero\n");
				break;
			case 6 :
				fprintf(stderr , "Error pow operation\n");
				break;
			case 7 :
				fprintf(stderr , "Error operator\n");
				break;
			case 10 :
				fprintf(stderr , "Wrong expression\n");
				break;
			default :
				fprintf(stderr , "Code error\n");
				break;
		}
};








