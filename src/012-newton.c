#include <include/all.h>
double df(double x, double (*func)(double)) {
    double h = 0.0001;
    return (func(x + h) - func(x - h)) / (2.0 * h);
}

double newton(double start, double (*func)(double)) {
    uint32_t count = 100;

    FILE *fp = fopen("../data/012-newton.dat", "w");
    if (fp == NULL) {
        fputs("ファイルオープンに失敗しました。\n", stderr);
        exit(EXIT_FAILURE);
    }

    double a = start;
    double eps = 1.0 * pow(10, -7);

    for (uint32_t i = 0; i < count; i++) {
        fprintf(fp, "%d:x= %f f= %f\n", i, a, func(a));

        a -= func(a) / df(a, func);

        if (fabs(func(a) / df(a, func)) < eps) {
            break;
        }
    }

    fclose(fp);
}

double f(double x) { return x * x * x - 2.0; }

double g(double x) { return x * sin(x) - log(x); }

int main(int argc, char *argv[]) {
    // newton(2.0, f);
    newton(3.0, g);
}