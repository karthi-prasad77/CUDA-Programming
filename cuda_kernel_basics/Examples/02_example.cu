#include <cuda_runtime.h>
#include <stdio.h>

void __global__ findThread(int height, int width)
{
    int x = blockDim.x * blockIdx.x + threadIdx.x;
    int y = blockDim.y * blockIdx.y + threadIdx.y;

    if (x < width && y < height)
    {
        if (x == 4 && y == 2)
        {
            printf("Found Thread! -> Block(%d, %d) Thread(%d, %d)\n", 
            blockIdx.x, blockIdx.y,
            threadIdx.x, threadIdx.y);
        }
    }
}

int main()
{
    int width = 8;
    int heigth = 3;

    dim3 threads(2, 2);
    dim3 blocks (
        (width + threads.x -1) / threads.x,
        (heigth + threads.y - 1) / threads.y
    );

    findThread<<<blocks, threads>>>(heigth, width);

    cudaDeviceSynchronize();

    return 0;
}