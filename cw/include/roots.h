#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>


// Поиск корней уравнений
float root(func f, func g, float a, float b, float eps);
//find_roots - поиск корней между  f1(x), f2(x), f3(x). fn - массив функций, *roots - указатель на массив корней
void find_roots(func fn[], float *roots);
float root2(func f, func g, float a, float b, float eps);
void find_roots2(func fn[], float *roots);


