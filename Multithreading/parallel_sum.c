// windows powershell: cl
#include <stdio.h>
#include <stdbool.h>
#include <threads.h>

#define MAX_THREADS 8       // 1...8 number of max threads to create
#define MIN_BLOCK_SIZE 100  // Minimum size of an array block
#define N 50

// Arguments for the parallel_sum function
typedef struct {
  int* start;
  int len;
  int block_size;
  int sum;
} Sum_arg;

// Prototypes
bool sum(int arr[], int len, int* sumPtr);
int parallel_sum(void* arg);

int main(void) {

  int a[N];

  for (int i = 0; i < N; ++i)
  {
    a[i] = i+1;
  }

  int result = 0;

  sum(a, N, &result);

  printf("The result of the sum is %d", result);

  return 0;
}

bool sum(int arr[], int len, int* sumPtr) {
  int block_size = len / MAX_THREADS;
  if (block_size < MIN_BLOCK_SIZE) block_size = len;

  Sum_arg args = { arr, len, block_size, 0 };
  printf("[sum] Address of Sum_arg: %p\n", &args);

  parallel_sum(&args);

  *sumPtr = args.sum;
  return false;
}

int parallel_sum(void* arg) {

  Sum_arg* argp = (Sum_arg*)arg; // A pointer to the arguments
  printf("[parallel_sum] Address of Sum_arg: %p\n", argp);

  if (argp->len <= argp->block_size)
  {
    for (int i = 0; i < argp->len; ++i)
    {
      argp->sum += argp->start[i];
    }
    return 1;
  }
  else
  {
    int mid = argp->len / 2;
    Sum_arg arg2 = { argp->start + mid, argp->len - mid, argp->block_size, 0 };
  }

  return 0;
}
