#include <cuda_runtime.h>
#include <stdio.h>
#include <iostream>

void __global__ square(int *A, int *B)
{
    // get the global index of the thread
    int globalIdx = blockIdx.x * blockDim.x + threadIdx.x;

    B[globalIdx] = A[globalIdx] * A[globalIdx];
    
}

int main()
{
    // Grid - contains multiple blocks
    // blocks cannot communicate directly
    int input[4] = {1, 2, 3, 4};
    int size = sizeof(input) / sizeof(input[0]);
    int output[size] = {0};

    int *d_A, *d_B;

    cudaMalloc(&d_A, size * sizeof(int));
    cudaMalloc(&d_B, size * sizeof(int));

    cudaMemcpy(d_A, input, size * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, output, size * sizeof(int), cudaMemcpyHostToDevice);

    square<<<2, 4>>>(d_A, d_B);

    cudaDeviceSynchronize();

    cudaMemcpy(output, d_B, size * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i<size; i++)
    {
        std::cout << output[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}