#include <cstdio>

__global__ void hello2Dthreads()
{
    int x = threadIdx.x;
    int y = threadIdx.y;

    // x -> columns, y -> rows
    printf("threadIdx = (%d, %d)\n", x, y);
}

__global__ void hello2Dblocks()
{
    printf("blocks=(%d, %d), threads=(%d, %d)\n", blockIdx.x, blockIdx.y, threadIdx.x, threadIdx.y);
}

__global__ void global2Dindex()
{
    int x = blockDim.x * blockIdx.x + threadIdx.x;
    int y = blockDim.y * blockIdx.y + threadIdx.y;

    printf("blocks = (%d, %d), threads = (%d, %d) -> globalIdx = (%d, %d)\n", 
        blockIdx.x, blockIdx.y, threadIdx.x, threadIdx.y, x, y
    );
}

int main()
{
    // create a 2D thread
    dim3 blocks(3, 2);

    // create a 2D blocks
    dim3 grids(2, 2);

    hello2Dthreads<<<1, blocks>>>();

    //hello2Dblocks<<<grids, blocks>>>();

    global2Dindex<<<grids, blocks>>>();

    cudaDeviceSynchronize();

    return 0;
}