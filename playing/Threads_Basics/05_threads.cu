#include <cuda_runtime.h>
#include <stdio.h>

void __global__ printGlobal2D()
{
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;

    printf("Global: (%d, %d)\n", x, y);
}

int main()
{
    // combine the both 2D blocks and threads
    dim3 threads(2, 2);
    dim3 blocks(2, 2);

    // total threads -> (2x2) blocks * (2*2) threads = 4 * 4 = 16 total threads
    // 4 blocks and 4 threads per block
    printGlobal2D<<<blocks, threads>>>();

    cudaDeviceSynchronize();

    return 0;
}