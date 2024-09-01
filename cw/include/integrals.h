#include <stdio.h>


//integral - calculates an integral of function f in [a,b] with eps2 accuracy
float integral(func f, float a, float b, float eps2);

//find_integrals - find ingegrals of functions in fn[] array.
void find_integrals(func fn[], float *roots, float *integrals);