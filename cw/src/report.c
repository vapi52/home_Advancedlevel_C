#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>

#include "functions.h"
#include "roots.h"
#include "plot.h"
#include "integrals.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        char *opts = "hrpts";
        int32_t opt = 0;
        func fn[FUNC_COUNT] = {&f0, &f1, &f2};
        float roots[3];
        float integrals[3];

        while ((opt = getopt(argc, argv, opts)) != -1)
        {
            switch (opt)
            {
            case 'h':
                print_help();
                break;    
            case 'r':
                printf("--------------------------\n");
                find_roots(fn, roots);
                printf("--------------------------\n");
                break;
            case 'p':
                plot_functions(fn, 0.5, 4.3, 100);
                break;
            case 't':
                printf("------------------------------------------\n");
                printf("Testing root and integral functions...\n");
                printf("------------------------------------------\n");
                find_roots(fn, roots);
                printf("------------------------------------------\n");
                find_integrals(fn, roots, integrals);
                printf("------------------------------------------\n");
                break;
            case 's':
                find_roots2(fn, roots);               
                printf("----------------------------------------------------\n");
                find_integrals(fn, roots, integrals);
                printf("----------------------------------------------------\n");
                printf("Square between f0(x), f1(x) and f2(x) = %f\n", integrals[0] - integrals[1] - integrals[2]);
                printf("----------------------------------------------------\n");
                break;
            default:
                print_help();   
            }
        }
    }
    else
    {
        print_help();
    }
    return 0;
}
