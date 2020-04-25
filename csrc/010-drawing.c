#include <include/all.h>

double function(double x) { return x * sin(x) - log(x); }

int main(int argc, char *argv[]) {
    FILE *fp = fopen("../data/010-drawing.dat", "w");
    if (fp == NULL) {
        fputs("ファイルオープンに失敗しました。\n", stderr);
        exit(EXIT_FAILURE);
    }

    uint32_t count = 100;

    for (uint32_t i = 0; i < count; i++) {
        double x = i * 5.0 / count;

        fprintf(fp, "x= %f   y= %f\n", x, sin(x));
    }

    fclose(fp);
}