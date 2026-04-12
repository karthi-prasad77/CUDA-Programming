# 🚀 Introduction to CUDA Programming

## 📌 What is CUDA?

**CUDA (Compute Unified Device Architecture)** is a parallel computing platform and programming model developed by NVIDIA. It allows developers to use the power of a GPU (Graphics Processing Unit) for general-purpose computing.

Instead of running code only on the CPU, CUDA lets you run thousands of operations simultaneously on the GPU — making programs much faster for certain tasks.

---

## ⚡ Why Use CUDA?

CUDA is useful when:

* You have **large data** to process
* The same operation is applied repeatedly (parallel tasks)
* Performance is critical (e.g., AI, image processing)

### Examples:

* Deep Learning (Neural Networks)
* Image & Video Processing
* Scientific Simulations
* Game Physics

---

## 🧠 CPU vs GPU (Simple Idea)

| CPU 🧠                    | GPU ⚡                      |
| ------------------------- | -------------------------- |
| Few cores                 | Thousands of cores         |
| Good for sequential tasks | Best for parallel tasks    |
| Complex logic             | Simple repeated operations |

👉 Think:

* CPU = Manager (smart, few workers)
* GPU = Factory (many workers doing same job fast)

---

## 🏗️ CUDA Programming Model

CUDA follows a **host-device model**:

* **Host (CPU)** → Controls execution
* **Device (GPU)** → Executes parallel code

### Steps:

1. Allocate memory on GPU
2. Copy data from CPU → GPU
3. Run parallel function (kernel)
4. Copy result back to CPU

---

## 🔑 Key Concepts

### 1. Kernel

A function that runs on the GPU.

```cpp
__global__ void myKernel() {
    // runs on GPU
}
```

---

### 2. Threads

* Smallest unit of execution
* Thousands run in parallel

---

### 3. Blocks

* Group of threads

---

### 4. Grid

* Collection of blocks

👉 Structure:

```
Grid
 └── Blocks
      └── Threads
```

---

## 🧮 Example: Add Two Arrays

### CPU Version (Slow)

```cpp
for (int i = 0; i < N; i++) {
    C[i] = A[i] + B[i];
}
```

---

### CUDA Version (Parallel 🚀)

```cpp
__global__ void add(int *A, int *B, int *C) {
    int i = threadIdx.x;
    C[i] = A[i] + B[i];
}

int main() {
    add<<<1, N>>>(A, B, C);
}
```

👉 Each thread handles one element!

---

## 🧠 Memory Types in CUDA

| Memory Type     | Description               |
| --------------- | ------------------------- |
| Global Memory   | Large but slow            |
| Shared Memory   | Fast, shared within block |
| Local Memory    | Private to thread         |
| Constant Memory | Read-only, fast           |

---

## ⚙️ Compilation

CUDA uses **nvcc compiler**:

```bash
nvcc program.cu -o program
```

---

## ⚡ When NOT to Use CUDA?

Avoid CUDA when:

* Task is small
* Not parallelizable
* CPU is already sufficient

---

## 🛠️ Requirements

* NVIDIA GPU
* CUDA Toolkit
* Compatible Drivers

---

## 📈 Learning Path

1. Basics of C/C++
2. Parallel thinking
3. CUDA syntax
4. Memory management
5. Optimization (advanced)

---

## 🎯 Summary

* CUDA lets you use GPU for general computation
* Massive speedup for parallel tasks
* Uses kernels, threads, blocks, grids
* Widely used in AI and high-performance computing

---

## 🚀 Next Steps

* Write simple kernels
* Learn memory management deeply
* Explore performance optimization

---

Happy CUDA Learning! ⚡
