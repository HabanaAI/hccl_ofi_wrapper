CC = g++

ifeq (${LIBFABRIC_ROOT},)
root := /opt/libfabric
else
root := ${LIBFABRIC_ROOT}
endif

make:
	$(CC) -std=gnu++0x -I$(root)/include/ \
                -Wall -shared -o libhccl_ofi_wrapper.so -fPIC hccl_ofi_wrapper.cpp  \
		-L$(root)/lib/ -lfabric

dev:
	$(CC) -std=gnu++0x -I${HCL_ROOT}/include/ -I$(root)/include/ \
                -Wall -shared -o libhccl_ofi_wrapper.so -fPIC hccl_ofi_wrapper.cpp  \
		-L$(root)/lib/ -lfabric

clean:
	rm -f libhccl_ofi_wrapper.so