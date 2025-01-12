#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_STEPS 1000000000 // 1 billion steps

static inline double fn(double x) { 
    return 1.0 / (1.0 + x * x); 
}

double calculate_pi() {
  static const double STEP = 1.0 / NUM_STEPS;
  double sum = 0.0;
    
#pragma omp parallel for reduction(+:sum)
  for (int i = 0; i < NUM_STEPS; ++i) {
    double x = (i + 0.5) * STEP;
    sum += 1.0 / (NUM_STEPS)*fn(x);
  }

  return 4.0 * sum;
}

int main() {
  double start = omp_get_wtime();
  double pi = calculate_pi();
  double end = omp_get_wtime();
  printf("Calculated pi: %f\n", pi);
  printf("Elapsed time: %.8f\n", end - start);

  return 0;
}
