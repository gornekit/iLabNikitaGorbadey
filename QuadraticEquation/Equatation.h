//Equatation.h

#ifndef Equatation_H
#define Equatation_H

#include <stdio.h>
#include <math.h>

enum VARIETIVE_SOLVES
{

	NO_EQUATION,
	NO_SOLVE,
	ONE_SOLVE,
	NEGATIVE_DISCR,
	TWO_SAME_SOLVES,
	TWO_DIFFERENT_SOLVES

};

int input(double *inp, int length) ;
VARIETIVE_SOLVES solve(const double *inp, int length);
void output(VARIETIVE_SOLVES k,double *inp, int length );



VARIETIVE_SOLVES k;
double inp[3];
int lenght;
char repetition;

#endif //Equatation_H

