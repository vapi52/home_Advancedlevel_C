#include <stdio.h>
#include <stdint.h>

// Количество функций
#define FUNC_COUNT 3

typedef float (* func)(float);
float f0(float x);
float f1(float x);
float f2(float x);
void print_help();


