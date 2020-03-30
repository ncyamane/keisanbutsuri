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

  // Choose the pivot
  for (uint32_t i = 0; i < DIM; i++) {
    printf("Pivot\n");
  }

  for (uint32_t i = 0; i < DIM; ++i) {
    for (uint32_t j = i + 1; j < DIM; ++j) {
      double c = mat_a[j * DIM + i] / mat_a[i * DIM + i];
      for (uint32_t k = i; k < DIM; ++k) {
        B[j * n + k] = B[j * n + k] - c * B[i * n + k];
      }
    }
  }

  Printmatrix(DIM, DIM, mat_a);
  printf("\n");
  Printmatrix(DIM, 1, vec_b);
  printf("\n");

  double x[3] = {0};
  for (uint32_t i = n - 1; i >= 0; --i) {
    for (uint32_t j = i + 1; j < n; ++j) {
      x[i] -= B[i * n + j] * x[j];
    }
    x[i] += B[i * n + n];
    x[i] /= B[i * n + i];
  }

  for (uint32_t i = 0; i < n; ++i) {
    printf("%lf ", x[i]);
  }
}