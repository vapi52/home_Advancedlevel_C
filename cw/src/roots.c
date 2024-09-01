#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "roots.h"

// Поиск точек пересечения кривых методом хорд
float root(func f, func g, float a, float b, float eps) {
    size_t stepcount=0;
    while(fabs(b - a) > eps) {
        float fa = f(a), fb = f(b), ga = g(a), gb = g(b);
        a = b - (b - a) * (fb - gb) / (fb - gb + ga - fa);
        b = a - (a - b) * (fa - ga) / (fa - ga + gb - fb);
        stepcount++;
    }
    printf("%lld steps for ",stepcount);
    return b;
}

void find_roots(func fn[], float *roots) {
    roots[0] = root(fn[0],fn[2], 0.5, 1, 0.00001);
    printf("root(f0, f2) = %f\n", roots[0]);

    roots[1] = root(fn[1],fn[2], 3, 3.5, 0.00001);
    printf("root(f1, f2) = %f\n", roots[1]);

    roots[2] = root(fn[0],fn[1], 3.5, 4, 0.00001);
    printf("root(f0, f1) = %f\n", roots[2]);
}

float root2(func f, func g, float a, float b, float eps) {
    size_t stepcount=0;
    while(fabs(b - a) > eps) {
        float fa = f(a), fb = f(b), ga = g(a), gb = g(b);
        a = b - (b - a) * (fb - gb) / (fb - gb + ga - fa);
        b = a - (a - b) * (fa - ga) / (fa - ga + gb - fb);
        stepcount++;
    }
    return b;
}

void find_roots2(func fn[], float *roots) {
    roots[0] = root2(fn[0],fn[2], 0.5, 1, 0.00001);
    roots[1] = root2(fn[1],fn[2], 3, 3.5, 0.00001);
    roots[2] = root2(fn[0],fn[1], 3.5, 4, 0.00001);
    
}