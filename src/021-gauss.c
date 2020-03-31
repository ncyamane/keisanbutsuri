#include <include/all.h>

// Gaussian Elimination with partial pivoting

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

    for (uint32_t i = 0; i < DIM; ++i) {
        // Choose the pivot
        uint32_t p = i;
        double pivot = mat_a[i * DIM + i];
        for (uint32_t j = i + 1; j < DIM; ++j) {
            if (fabs(pivot) < fabs(mat_a[j * DIM + i])) {
                p = j;
                pivot = mat_a[j * DIM + i];
            }
        }
        // Swap the rows
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

        // Forward Substitution
        for (uint32_t j = i + 1; j < DIM; ++j) {
            double c = mat_a[j * DIM + i] / mat_a[i * DIM + i];
            vec_b[j] -= vec_b[i] * c;
            for (uint32_t k = i; k < DIM; ++k) {
                mat_a[j * DIM + k] -= mat_a[i * DIM + k] * c;
            }
        }
    }

    Printmatrix(DIM, DIM, mat_a);
    Printmatrix(DIM, 1, vec_b);

    // Backward substitution
    for (int32_t i = DIM - 1; i >= 0; --i) {
        for (uint32_t j = i + 1; j < DIM; ++j) {
            vec_b[i] -= mat_a[i * DIM + j] * vec_b[j];
        }
        vec_b[i] /= mat_a[i * DIM + i];
    }

    Printmatrix(DIM, 1, vec_b);
}