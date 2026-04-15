#include <cuda_runtime.h>
#include <stdio.h>

void __global__ print2Dthreads()
{
    printf("Thread (%d, %d)\n", threadIdx.x, threadIdx.y);
}

int main()
{
    // 2-Dimension threads in CUDA
    // threadIdx.x, threadIdx.y
    // threadIdx.x -> column
    // threadIdx.y -> row
    dim3 threads(3, 2); // 3 columns and 2 rows
    print2Dthreads<<<1, threads>>>();

    cudaDeviceSynchronize();

    return 0;
}