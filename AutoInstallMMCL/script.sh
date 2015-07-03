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
