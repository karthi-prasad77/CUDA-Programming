#include <cuda_runtime.h>
#include <stdio.h>

void __global__ print1DThread()
{
    // threadIdx.x -> will provide a index of the current thread
    printf("Thread 1D: %d\n", threadIdx.x);
}


int main()
{
    // creating a 1D threads in CUDA
    print1DThread<<<1, 5>>>(); // 1 block -> 5 threads

    cudaDeviceSynchronize(); // wait until the GPU finishes the work

    return 0;
}