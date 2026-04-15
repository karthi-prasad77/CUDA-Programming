#include <cuda_runtime.h>
#include <stdio.h>

void __global__ printBlockThreads()
{
    // blockIdx.x - it will provide the current block index
    // threadIdx.x - it will provide the current thread index
    // Note: Order will not guranteed
    printf("Block: %d, Thread: %d\n", blockIdx.x, threadIdx.x);
}

int main()
{
    // Block - group of threads
    // thread inside the block:
        // Can communicate (shared memory)
        // Can sync(_syncthreads())
    printBlockThreads<<<2, 3>>>(); // 2 blocks, 3 threads per block

    cudaDeviceSynchronize();

    return 0;
}