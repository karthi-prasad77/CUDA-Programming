#include <cuda_runtime.h>
#include <stdio.h>

void __global__ findGlobalIndex()
{
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    printf("GlobalIndex for (%d, %d) - %d\n", blockIdx.x, threadIdx.x, idx);
}

int main()
{
    // threads and blocks
    dim3 threads(5);
    dim3 blocks(3);

    // Question:
    /*
        For:
            blockIdx.x = 2
            threadIdx.x = 3

        To find global index idx
    */

    findGlobalIndex<<<blocks, threads>>>();

    cudaDeviceSynchronize();

    return 0;
}