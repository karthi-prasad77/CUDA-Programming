#include <cstdio>
#include <cuda_runtime.h>
#include <iostream>

__global__ void vecAddition(const float* A, const float* B, float* C, int N)
{

    int globalIdx = blockDim.x * blockIdx.x + threadIdx.x;

    if (globalIdx < N)
    {
        C[globalIdx] = A[globalIdx] + B[globalIdx];
    }

}

int main()
{
    const int N = 8;
    const size_t bytes = N * sizeof(float);

    // array in the host machine
    float h_A[N] = {1, 2, 3, 4, 5, 6, 7, 8};
    float h_B[N] = {10, 20, 30, 40, 50, 60, 70, 80};
    float h_C[N];

    // variables for device machine
    float* d_A;
    float* d_B;
    float* d_C;

    // create a memory in CUDA
    cudaMalloc(&d_A, bytes);
    cudaMalloc(&d_B, bytes);
    cudaMalloc(&d_C, bytes);

    // copy the data from host to device
    cudaMemcpy(d_A, h_A, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, bytes, cudaMemcpyHostToDevice);

    // define the threads and blocks
    int threadsPerBlock = 8;
    int blocks = (N + threadsPerBlock - 1) / threadsPerBlock;

    // invoke the CUDA kernel
    vecAddition<<<blocks, threadsPerBlock>>>(d_A, d_B, d_C, N);

    cudaDeviceSynchronize(); // wait until the GPU operation completes

    cudaMemcpy(h_C, d_C, bytes, cudaMemcpyDeviceToHost);

    for (int i = 0; i<N; i++)
    {
        std::cout << h_A[i] << " + " << h_B[i] << " = " << h_C[i] << std::endl;
    }

    // free the allocated memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;

}