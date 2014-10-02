//Solve quadratic equation
//By Gorbadey Nikita

#include "Equatation.h"

int main()
{
    VARIETIVE_SOLVES k;
    double inp[3];
	int lenght;
	char repetition='y';

    while(repetition=='y')
    {
        input(&inp, 3);
        k=solve(inp, 3);
        output(VARIETIVE_SOLVES k, &inp ,3);
        printf("Repeat? y-yes, n-no\n");
        scanf("%ch", &repetition);
    }
    return 0;
}

