GCC = gcc
NVCC = nvcc
CUDA_FLAGS = -arch=sm_86

01: 01.c
	@$(GCC) 01.c -o ./build/01

# just compile to object file
01_obj:
	@$(GCC) -c 01.c -o ./build/01.o

# compile and runs the object file (ensure 01_obj is up to 
# date by running 01_obj first if it hasn't been run yet)
01_obj_exe_run: 01_obj
	@$(GCC) ./build/01.o -o ./build/01
	@./build/01

02: 02.c
	@$(GCC) 02.c -o ./build/02

03: 03.cu
	@$(NVCC) $(CUDA_FLAGS) -o 03.cu ./build/03

clean:
# need to check the windows command to remove the binaries