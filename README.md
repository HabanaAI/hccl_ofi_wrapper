# HCCL OFI Wrapper
HCCL (Habana Collective Communication Library) supports inter-node communication based on OFI libfabric.<br />
HCCL OFI wrapper introduced to act as a thin layer connecting between HCCL and libfabric APIs.<br />

# Version
1.0.<br />

# HCCL OFI Wrapper
To use HCCL over libfabric, this wrapper should be built.<br />

Required steps:
1. Download and install libfabric
2. `git clone https://github.com/HabanaAI/hccl_ofi_wrapper.git`
3. `export LIBFABRIC_ROOT=<libFabric library location>`
4. `cd hccl_ofi_wrapper`
5. `make`
6. `cp libhccl_ofi_wrapper.so /usr/lib/habanalabs/libhccl_ofi_wrapper.so`
7. `ldconfig`
8. `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<hccl_ofi_wrapper.so location>`



