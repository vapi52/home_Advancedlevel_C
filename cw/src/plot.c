#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>
#include "functions.h"
#include "plot.h"

int8_t plot_functions(func fn[], float xl, float xr, int32_t step_cnt)
{
    int8_t res = 0;

    FILE *gnuplot_p = popen("gnuplot -persistent", "w");
    if (gnuplot_p != NULL)
    {

        fprintf(gnuplot_p, "set title 'Visualisation of functions. Pichugin-VA' font 'Helvetica Bold, 20'\n");
        fprintf(gnuplot_p, "set xlabel 'x'\n");
        fprintf(gnuplot_p, "set ylabel 'y'\n");
        fprintf(gnuplot_p, "set xrange [0.5:4.5]\n");
        fprintf(gnuplot_p, "set yrange [0:7]\n");
        fprintf(gnuplot_p, "set grid\n");

        char fname[20] = "_data.txt";
        FILE *f_data = fopen(fname, "w");
        if (f_data != NULL)
        {
            double x = 0, y = 0, step = 0;
            step = fabs(xr - xl) / step_cnt;
            for (int32_t j = 0; j < step_cnt; j++)
            {
                x = xl + j * step;
                fprintf(f_data, "%f ", x);
                for (int8_t i = 0; i < FUNC_COUNT; i++)
                {
                    y = fn[i](x);
                    fprintf(f_data, "%f ", y);
                }
                fprintf(f_data, "\n");
            }
            fclose(f_data);

            fprintf(gnuplot_p, "plot ");
            for (int8_t i = 0; i < FUNC_COUNT; i++)
            {
                fprintf(gnuplot_p, "'_data.txt' using 1:%d with lines title 'f%d(x)', ", i + 2, i);
            }

            fprintf(gnuplot_p, "\n");
        }

        fflush(gnuplot_p);
        pclose(gnuplot_p);
    }
    else
    {
        res = 1;
    }
    return res;
}
