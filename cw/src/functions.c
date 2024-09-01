#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

float f0(float x)
{
    return 0.6 * x + 3;
}

float f1(float x)
{
    return (x - 2) * (x - 2) * (x - 2) - 1;
}

float f2(float x)
{
    return 3 / x;
}

void print_help()
{
    printf("--------------------------\n");
    printf("Command line options:\n");
    printf("--------------------------\n");
    printf("-h :	print help\n");
    printf("-r :	find roots\n");
    printf("-s :	find square between f0(x), f1(x) and f2(x)\n");
    printf("-p :	plot graph\n");
    printf("-t :	test functions\n");
    printf("--------------------------\n");
}
