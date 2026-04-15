#include <cuda_runtime.h>
#include <stdio.h>
#include <iostream>

// NOTE: GPU memory is 1D
// row major order
// GOAL: need to convert (x, y) -> index in 1D array
// FORMULA: int idx = y * width + x;
// x -> column (left -> right)
// y -> row (top -> bottom)
// width -> number of columns
/*
    Examples:

        - if (x = 2, y =1) and width = 4 columns
        idx = 1 * 4 + 2 = 6 (0 - based indexing)
*/

void __global__ matrix(int *d_A, int *d_B, int *d_C, int width, int heigth)
{
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;

    if (x < width && y < heigth)
    {
        int idx = y * width + x;
        d_C[idx] = d_A[idx] + d_B[idx];
    }
}

int main()
{
    int width = 4; // 4 columns
    int height = 2; // 2 rows

    int size = width * height;

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int B[] = {1, 1, 1, 1, 1, 1, 1, 1};
    int C[size] = {0};

    int *d_A, *d_B, *d_C;

    cudaMalloc(&d_A, size * sizeof(int));
    cudaMalloc(&d_B, size * sizeof(int));
    cudaMalloc(&d_C, size * sizeof(int));

    cudaMemcpy(d_A, A, size * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, size * sizeof(int), cudaMemcpyHostToDevice);

    dim3 threads(2, 2);
    // threads.x = 2, threads.y = 2
    dim3 blocks (
        (width + threads.x - 1) / threads.x,
        (height + threads.y - 1) / threads.y
    );

    matrix<<<blocks, threads>>>(d_A, d_B, d_C, width, height);

    cudaDeviceSynchronize();

    cudaMemcpy(C, d_C, size * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i<height; i++)
    {
        for (int j = 0; j<width; j++)
        {
            std::cout << C[i * width + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}