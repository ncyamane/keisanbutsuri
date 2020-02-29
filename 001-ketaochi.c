#include "include/all.h"

int main()
{
    float a_f = sqrt(2);
    double a_d = sqrt(2);
    long double a = sqrt(2);

    //単精度, 倍精度, 拡張倍精度
    printf("float : %f, %fE\n", a_f, a_f);
    printf("double : %lf, %lE\n", a_d, a_d);
    printf("long double : %Lf, %LE\n", a, a);
}