// macOS: gcc parallel_sum_sequence.c -o parallel_sum
#include <stdbool.h>
#include <threads.h>

#define MAX_THREADS 8       // 1...8 number of max threads to create
#define MIN_BLOCK_SIZE 100  // Minimum size of an array block

// Arguments for the parallel_sum function
typedef struct {
    float *start;
    int len;
    int block_size;
    double sum;
} Sum_arg;

// Prototypes
bool sum(float arr[], int len, double* sumPtr);
int parallel_sum(void *arg);




