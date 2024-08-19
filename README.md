# HCCL OFI Wrapper

HCCL (Habana Collective Communication Library) supports inter-node communication based on OFI libfabric.<br />
HCCL OFI wrapper introduced to act as a thin layer connecting between HCCL and libfabric APIs.<br />

# Version

1.2.<br />

# Prerequisites

To use HCCL over OFI libfabric:

1. libfabric should be downloaded and installed.<br />
2. HCCL OFI Wrapper should be downloaded and built.<br />

## Download and install libfabric

libfabric should be downloaded and installed in order to use it.<br />
Please follow the instructions below:<br />

1. Define required version to be installed
   ```
   export REQUIRED_VERSION=<version> (for example: 1.20.0)
   ```
2. Download libfabric tarball from: https://github.com/ofiwg/libfabric/releases
   ```
   wget  https://github.com/ofiwg/libfabric/releases/download/v$REQUIRED_VERSION/libfabric-$REQUIRED_VERSION.tar.bz2 -P /tmp/libfabric
   ```
3. Store temporary download directory in stack
   ```
   pushd /tmp/libfabric
   ```
4. Open the file
   ```
   tar -xf libfabric-$REQUIRED_VERSION.tar.bz2
   ```
5. Define libfabric root location
   ```
   export LIBFABRIC_ROOT=<libFabric library location>
   ```
6. Create folder for libfabric
   ```
   mkdir -p ${LIBFABRIC_ROOT}
   ```
7. Change permissions for libfabric folder
   ```
   chmod 777 ${LIBFABRIC_ROOT}
   ```
8. Change directory to libfabric folder created after opening tar file
   ```
   cd libfabric-$REQUIRED_VERSION/
   ```
9. Configure libfabric
   ```
   ./configure --prefix=$LIBFABRIC_ROOT --with-synapseai=/usr
   ```
10. Build and install libfabric
    ```
    make -j 32 && make install
    ```
11. Remove temporary download directory from stack
    ```
    popd
    ```
12. Delete temporary download directory
    ```
    rm -rf /tmp/libfabric
    ```
13. Include LIBFABRIC_ROOT in LD_LIBRARY_PATH:
    ```
    export LD_LIBRARY_PATH=$LIBFABRIC_ROOT/lib:$LD_LIBRARY_PATH
    ```

    Installation can be verified by running: `fi_info --version`.<br />
    For more information please see: https://github.com/ofiwg/libfabric

## Build HCCL OFI wrapper

To use libfabric library, HCCL OFI wrapper should be built.<br />
Please follow the instructions below:<br />

1. Clone wrapper from https://github.com/HabanaAI/hccl_ofi_wrapper
   ```
   git clone https://github.com/HabanaAI/hccl_ofi_wrapper.git
   ```
2. Define LIBFABRIC_ROOT
   ```
   export LIBFABRIC_ROOT=<libFabric library location>
   ```
3. Change directory to hccl_ofi_wrapper
   ```
   cd hccl_ofi_wrapper
   ```
4. Build wrapper
   ```
   make
   ```
5. Copy wrapper to /usr/lib/habanalabs/
   ```
   cp libhccl_ofi_wrapper.so /usr/lib/habanalabs/libhccl_ofi_wrapper.so
   ```
6. Run ldconfig utility
   ```
   ldconfig
   ```
7. Include libhccl_ofi_wrapper.so location in LD_LIBRARY_PATH:
   ```
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/habanalabs/
   ```


