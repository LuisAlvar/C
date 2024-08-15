// windows powershell: cl
#include <stdio.h>
#include <stdbool.h>
#include <threads.h>

#define MAX_THREADS 8       // 1...8 number of max threads to create
#define MIN_BLOCK_SIZE 100  // Minimum size of an array block
#define N 1024

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

/// <summary>
/// Recurisve helper function to divide the work among several threads.
/// </summary>
/// <param name="arg">List of arguments of struct type Sum_arg.</param>
/// <returns>Returns 1 if successfully. Otherwise 0.</returns>
int parallel_sum(void* arg) {

  Sum_arg* argp = (Sum_arg*)arg; // A pointer to the arguments
 
  if (argp->len <= argp->block_size)
  {
    // If length <= block_size add up the element
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
    argp->len = mid;

    thrd_t th;
    int res = 0;
    if (thrd_create(&th, parallel_sum, arg) != thrd_success)
    {
      return 0;
    }

    if (!parallel_sum(&arg2))
    {
      thrd_detach(th);
      return 0;
    }

    printf("New thread running: %d with \n", th._Tid);
    thrd_join(th, &res);
    if (!res)
    {
      return 0;
    }
    
    argp->sum += arg2.sum;
    return 1;
  }
}
