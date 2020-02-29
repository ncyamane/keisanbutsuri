#include "include/all.h"

double bisection(double start, double end, double (*func)(double))
{
    uint32_t count = 100;

    FILE *fp = fopen("data/011-bisection.dat", "w");
    if (fp == NULL)
    {
        fputs("ファイルオープンに失敗しました。\n", stderr);
        exit(EXIT_FAILURE);
    }

    double a = start;
    double b = end;
    double eps = 1.0 * pow(10, -7);

    for (uint32_t i = 0; i < count; i++)
    {
        double c = (a + b) / 2.0;

        double cond = func(a) * func(c);

        if (cond < 0)
        {
            a = a;
            b = c;
        }
        else if (cond > 0)
        {
            a = c;
            b = b;
        }

        fprintf(fp, "%d:x= %f f= %f\n", i, c, func(c));

        if (fabs(func(c)) < eps)
        {
            break;
        }
    }

    fclose(fp);
}

double f(double x)
{
    return x * x * x - 2.0;
}

double g(double x)
{
    return x * sin(x) - log(x);
}

int main()
{
    //bisection(1.0, 2.0, f);
    bisection(2.0, 3.0, g);
}