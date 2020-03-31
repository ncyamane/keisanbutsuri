#include "include/all.h"

int main()
{
    uint32_t count = 100000000;
    double h = 1.0 / count;
    double Integral = 0.0;
    double Exact = 0.5;

    clock_t start = clock();

    for (uint32_t i = 0; i < count; i++)
    {
        double a = 1.0 + h * i;

        Integral += h / (a * a);
    }

    clock_t end = clock();

    printf("I = %g\n", Integral);
    printf("E = %g\n", Integral - Exact);
    printf("time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
}