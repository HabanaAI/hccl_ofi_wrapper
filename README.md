# hccl_ofi_wrapper

HCCL (Habana Collective Communication Library) supports inter-Nodes communication based on OFI libFabric.
HCCL OFI wrapper introduced to act as a thin layer connecting between HCCL and libFabric APIs. 

Build

In order to use HCCL over libFabric, this wrapper should be built.
After downloading and installing libFabric, HCCL OFI wrapper should be downloaded and “make” command should be triggered from the wrapper directory.
When running HCCL, the wrapper path should be added to the LD library path. For example:
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<hccl_ofi_wrapper.so location>
