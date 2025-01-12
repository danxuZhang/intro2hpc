#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_STEPS 1000000000 // 1 billion steps

static inline double fn(double x) {
    return 1.0 / (1.0 + x * x);
}

int main(int argc, char *argv[]) {
  int rank, size, error;
  double pi = 0.0, sum = 0.0;
  double start_time, end_time;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  start_time = MPI_Wtime();

  const int steps_per_proc = NUM_STEPS / size;
  const double step = 1.0 / NUM_STEPS;

  const int start = rank * steps_per_proc;
  const int end = (rank == size - 1) ? NUM_STEPS : start + steps_per_proc;

  double local_sum = 0.0;
  for (int i = start; i < end; i++) {
    double x = (i + 0.5) * step;
    local_sum += fn(x);
  }
  local_sum *= step;

  MPI_Reduce(&local_sum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if (rank == 0) {
    pi = 4.0 * sum;
    end_time = MPI_Wtime();

    printf("Calculated π = %.16f\n", pi);
    printf("Computation time: %f seconds\n", end_time - start_time);
  }

  MPI_Finalize();
  return 0;
}

