#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>
#include "functions.h"

// plot functions in [a,b]. fn[] - array of functions
int8_t plot_functions(func fn[], float xl, float xr, int32_t step_cnt);
