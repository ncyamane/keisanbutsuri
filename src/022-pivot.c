#include "include/all.h"

#define DIM 3

void Printmatrix(uint32_t row_size, uint32_t column_size, double *matrix) {
    for (uint32_t i = 0; i < row_size; ++i) {
        for (uint32_t j = 0; j < column_size; ++j) {
            printf("%lf ", matrix[i * column_size + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    double mat_a[DIM * DIM] = {1, -4, 3, 1, -3, 2, 2, -1, 3};
    Printmatrix(DIM, DIM, mat_a);

    double vec_b[DIM] = {-1, 2, 0};
    Printmatrix(DIM, 1, vec_b);

    for (uint32_t i = 0; i < DIM; ++i) {
        uint32_t p = i;
        double pivot = mat_a[i * DIM + i];
        for (uint32_t j = i + 1; j < DIM; ++j) {
            if (fabs(pivot) < fabs(mat_a[j * DIM + i])) {
                p = j;
                pivot = mat_a[j * DIM + i];
            }
        }
        if (p != i) {
            for (uint32_t k = i; k < DIM; ++k) {
                double s = mat_a[i * DIM + k];
                mat_a[i * DIM + k] = mat_a[p * DIM + k];
                mat_a[p * DIM + k] = s;
            }
            double s = vec_b[i];
            vec_b[i] = vec_b[p];
            vec_b[p] = s;
        }
    }

    Printmatrix(DIM, DIM, mat_a);
    Printmatrix(DIM, 1, vec_b);
}