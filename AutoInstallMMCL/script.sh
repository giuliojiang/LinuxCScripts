mkdir /opt/metamorphicCL/
mkdir /opt/metamorphicCL/llvm
cd /opt/metamorphicCL/llvm
svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm
cd llvm/tools
svn co http://llvm.org/svn/llvm-project/cfe/trunk clang
cd ../..
cd llvm/tools/clang/tools
svn co http://llvm.org/svn/llvm-project/clang-tools-extra/trunk extra
cd ../../../..
cd llvm/projects
svn co http://llvm.org/svn/llvm-project/compiler-rt/trunk compiler-rt
cd ../..
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE:STRING=Release ../llvm/
make -j8
mkdir /opt/metamorphicCL/spir
mkdir /opt/metamorphicCL/spir/headers
cd /opt/metamorphicCL/spir/headers
wget https://github.com/KhronosGroup/SPIR-Tools/raw/master/headers/opencl_spir.h
cd /opt/metamorphicCL/
git clone https://github.com/mc-imperial/gpuverify.git GPUVerify
cd /opt/metamorphicCL/
git clone https://gitlab.doc.ic.ac.uk/multicore/metamorphiccl.git
mkdir /opt/metamorphicCL/metamorphicCLbuild/
cd /opt/metamorphicCL/metamorphicCLbuild/
cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_CONFIG=./../llvm/build/bin/llvm-config /opt/metamorphicCL/metamorphiccl/libtooling/
make -j8
