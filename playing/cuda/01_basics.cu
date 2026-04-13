#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>

__global__ void add(int *A, int *B, int *C, int N)
{
    // global index
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (i < N)
    {
        C[i] = A[i] + B[i];
    }
}

int main()
{
    int N = 10;

    int A[N], B[N], C[N];

    // intialize the data
    for (int i = 0; i< N; i++)
    {
        A[i] = i;
        B[i] = i*2;
    }

    // create a data for GPU
    int *d_A, *d_B, *d_C;

    // allocate the memory in GPU
    cudaMalloc(&d_A, N * sizeof(int));
    cudaMalloc(&d_B, N * sizeof(int));
    cudaMalloc(&d_C, N * sizeof(int));

    cudaMemcpy(d_A, A, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, N * sizeof(int), cudaMemcpyHostToDevice);

    add<<<3, 4>>>(d_A, d_B, d_C, N); // 3 blocks and 4 threads in each block

    cudaError_t err = cudaGetLastError();
    if (err != cudaSuccess) {
        std::cout << "Kernel launch error: "
                << cudaGetErrorString(err) << std::endl;
    }

    // Wait for all GPU threads to finish
    cudaDeviceSynchronize();

    cudaMemcpy(C, d_C, N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i<N; i++)
    {
        std::cout << C[i] << " ";
    }

    // free up the memory in GPU
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}


/*

#include <iostream>
using namespace std;

__global__ void add(int *A, int *B, int *C, int N) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    if (i < N) {  // avoid out-of-bounds
        C[i] = A[i] + B[i];
    }
}

int main() {
    int N = 10;

    int A[N], B[N], C[N];

    for (int i = 0; i < N; i++) {
        A[i] = i;
        B[i] = i * 2;
    }

    int *d_A, *d_B, *d_C;

    cudaMalloc(&d_A, N * sizeof(int));
    cudaMalloc(&d_B, N * sizeof(int));
    cudaMalloc(&d_C, N * sizeof(int));

    cudaMemcpy(d_A, A, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, N * sizeof(int), cudaMemcpyHostToDevice);

    add<<<3, 4>>>(d_A, d_B, d_C, N); // 3 blocks, 4 threads

    cudaMemcpy(C, d_C, N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; i++) {
        cout << C[i] << " ";
    }

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
}

*/