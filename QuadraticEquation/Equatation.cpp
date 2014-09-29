//Functions description

#include "Equatation.h"


int input(double* inp, int length)
{
    printf("Enter coficents of quadratic equation\n");
    for(int i=0; i<length; i++)
	{
        scanf("%lf", &inp[i]);
	}
	return 0;
};
VARIETIVE_SOLVES solve(const double *inp, int length)
{
   if (inp[0]==0&&inp[1]==0&&inp[2]==0)
     return NO_EQUATION;
   if(inp[0]==0&&inp[1]==0)
    return NO_SOLVE;
   if(inp[0]==0)
    return ONE_SOLVE;
   if ((sqr(inp[1])-4*inp[0]*inp[2])<0)
    return NEGATIVE_DISCR;
   if((sqr(inp[1])-4*inp[0]*inp[2])==0)
    return TWO_SAME_SOLVES;
   if ((sqr(inp[1])-4*inp[0]*inp[2])>0)
    return TWO_DIFFERENT_SOLVES;
};

void output(VARIETIVE_SOLVES k, double *inp, int length )
{
	switch (k,double* inp, int length)
	{
		case 1 :
		    printf("There's no equatation\n");
		    break;
		case 2 :
		    printf("There's no solves\n");
		    break;
		case 3 :
		    printf("One solve : %.2lf\n", -inp[2]/inp[1]);
		    break;
		case 4 :
		    printf("No real solves (negative discriminant)\n");
		    break;
		case 5 :
		    printf("Two same solves, %.2lf\n", -inp[1]/(2*inp[0]));
		    break;
		case 6 :
		    printf("Two defferent solves, %.2lf , %.2lf\n",  (-inp[1]+sqrt((pow(inp[1])-4*inp[0]*inp[2]))/(2*inp[0])),
															    ((-inp[1]-sqrt((sqr(inp[1])-4*inp[0]*inp[2]))/(2*inp[0]))));
            break;
        default :
            break;
	}
};
