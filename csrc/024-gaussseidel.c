#include <include/all.h>

// Gauss-Seidel method

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

int main(int argc, char *argv[]) {
    double mat_a[DIM * DIM] = {1, -4, 3, 1, -5, 2, 1, -1, 1};
    Printmatrix(DIM, DIM, mat_a);

    double vec_b[DIM] = {-1, 2, 0};
    double vec_x[DIM] = {};
    double vec_y[DIM] = {};

    for (uint32_t l = 0; l < 100; ++l) {
        for (uint32_t i = 0; i < DIM; ++i) {
            vec_x[i] = vec_b[i];
            vec_y[i] = vec_x[i];
            for (uint32_t j = 0; j < DIM; ++j) {
                if (i == j) continue;
                vec_x[i] -= mat_a[i * DIM + j] * vec_x[j];
            }
            vec_x[i] /= mat_a[i * DIM + i];
        }

        // Convergence
        double sum = 0;
        for (uint32_t i = 0; i < DIM; ++i) {
            sum += fabs(vec_x[i] - vec_y[i]);
            if (sum < 1.0e-4 * DIM) break;
        }

        Printmatrix(DIM, 1, vec_x);
    }
}