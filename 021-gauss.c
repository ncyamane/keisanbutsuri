#include "include/all.h"

#define DIM 3

void Printmatrix(uint32_t row_size, uint32_t column_size, double *matrix) {
    for (uint32_t i = 0; i < row_size; ++i) {
        for (uint32_t j = 0; j < column_size; ++j) {
            printf("%lf ", matrix[i * row_size + j]);
        }
        printf("\n");
    }
}

int main() {
    double mat_a[DIM * DIM] = {2, -3, -1, 3, -2, 2, 1, -2, 1};
    Printmatrix(DIM, DIM, mat_a);

    double vec_b[DIM] = {1, -3, -4};

    for (uint32_t i = 0; i < DIM; ++i) {
        // Choose the pivot
        printf("Pivot\n");
        for (uint32_t j = i + 1; j < DIM; ++j) {
            double pivot = mat_a[j * DIM + i] / mat_a[i * DIM + i];
            for (uint32_t k = i; k < DIM; ++k) {
                mat_a[j * DIM + k] -= mat_a[i * DIM + k] * pivot;
                vec_b[k] -= vec_b[k] * pivot;
            }
        }
    }

    Printmatrix(DIM, DIM, mat_a);
    printf("\n");
    Printmatrix(DIM, 1, vec_b);
    printf("\n");

    double x[3] = {0};
    for (uint32_t i = DIM - 1; i >= 0; --i) {
        for (uint32_t j = i + 1; j < DIM; ++j) {
            x[i] -= mat_a[i * DIM + j] * x[j];
        }
        x[i] += mat_a[i * DIM + DIM];
        x[i] /= mat_a[i * DIM + i];
    }

    for (uint32_t i = 0; i < DIM; ++i) {
        printf("%lf ", x[i]);
    }
}