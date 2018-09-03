/*====================================================*\
  Vendredi 8 novembre 2013
  Arash HABIBI
  Complex.h
\*====================================================*/

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <stdio.h>
#include <stdlib.h>

typedef double scalar;

typedef struct
{
	scalar _real, _imgn;
} Complex;

Complex CX_new(scalar real, scalar imgn);

void CX_check(Complex z, char *message);

Complex CX_add(Complex z1, Complex z2);
Complex CX_square(Complex z);

scalar CX_squareModule(Complex z);



#endif
