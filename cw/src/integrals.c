#include <math.h>
#include <stdio.h>
#include "functions.h"
#include "integrals.h"


// Поиск интеграла методом трапеции
float integral(func f, float a, float b, float eps2) {
    float sum = 0;
    float h = (b - a) * eps2;
    for(float x = a + h; x < b - h; x += h) {
        sum += 0.5 * h * (f(x) + f(x + h));
    }
    return sum;
}

void find_integrals(func fn[], float *roots, float *integrals) {
    integrals[0] = integral(fn[0], roots[0], roots[2], 0.00001);
    integrals[1] = integral(fn[1], roots[1], roots[2], 0.00001);
    integrals[2] = integral(fn[2], roots[0], roots[1], 0.00001);
    printf("Square f0(x) = %f\nSquare f1(x) = %f\nSquare f2(x) = %f\n", integrals[0], integrals[1], integrals[2]);

}

