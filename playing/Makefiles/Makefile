GCC = gcc
NVCC = nvcc
CUDA_FLAGS = -arch=sm_75

01: 12.c
	@$(GCC) -o ../output/12 12.c

02_obj: 12.c
	@$(GCC) -c 12.c -o ../output/12.o

03_obj_exe: 12.c
	@$(GCC) -o ../output/12 12.c
	@../output/12

04_cuda: 13.cu
	@$(NVCC) $(CUDA_FLAGS) -o ../output/13_cu 13.cu