#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <stdlib.h>
using namespace std;


int main()
{
    // welcome message
    cout << "-----------------------" << endl;
    cout << "MetamorphicCL installer" << endl;
    cout << "-----------------------" << endl;
    cout << "Please make sure you have C/C++ compiler installed," << endl;
    cout << "make, cmake, git, subversion, python" << endl;
    cout << "Do not continue if you don't meet the requirements" << endl << endl;
    
    cout << "Do you want to proceed? (y/[n]) ";
    string answer;
    getline(cin, answer);
    
    if (!(answer.compare("y") == 0))
    {
        cout << "exiting" << endl;
        return 0;
    }
    
    ofstream out;
    out.open("script.sh");
    
    int returnCode;
    string inTemp;
    
    // prepare directory structure
    string HOME;
    cout << "Please enter the working directory" << endl;
    cout << "you want to use. Absolute path necessary: [/opt] ";
    getline(cin, HOME);
    if (HOME.compare("") == 0)
    {
        HOME = "/opt";
    }
    
    cout << "Please enter the number of concurrent" << endl;
    cout << "Make jobs: [4] ";
    int MAKE_J;
    getline(cin, inTemp);
    if (inTemp.compare("") == 0)
    {
        MAKE_J = 4;
    } else
    {
        MAKE_J = atoi(inTemp.c_str());
    }
    if (MAKE_J > 8)
    {
        MAKE_J = 8;
    }
    if (MAKE_J < 1)
    {
        MAKE_J = 1;
    }
    
    out << "mkdir " << HOME << "/metamorphicCL/" << endl;

    
    // llvm clang
    out << "mkdir " << HOME << "/metamorphicCL/llvm" << endl;
    out << "cd " << HOME + "/metamorphicCL/llvm" << endl;
    out << "svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm" << endl;
    out << "cd llvm/tools" << endl;
    out << "svn co http://llvm.org/svn/llvm-project/cfe/trunk clang" << endl;
    out << "cd ../.." << endl;
    out << "cd llvm/tools/clang/tools" << endl;
    out << "svn co http://llvm.org/svn/llvm-project/clang-tools-extra/trunk extra" << endl;
    out << "cd ../../../.." << endl;
    out << "cd llvm/projects" << endl;
    out << "svn co http://llvm.org/svn/llvm-project/compiler-rt/trunk compiler-rt" << endl;
    out << "cd ../.." << endl;
    
    out << "mkdir build" << endl;
    out << "cd build" << endl;
    out << "cmake -DCMAKE_BUILD_TYPE:STRING=Release ../llvm/" << endl;
    out << "make -j" << MAKE_J << endl;

    // spir
    out << "mkdir " << HOME << "/metamorphicCL/spir" << endl;
    out << "mkdir " << HOME << "/metamorphicCL/spir/headers" << endl;
    out << "cd " << HOME << "/metamorphicCL/spir/headers" << endl;
    out << "wget https://github.com/KhronosGroup/SPIR-Tools/raw/master/headers/opencl_spir.h" << endl;
    
    // gpuverify
    out << "cd " << HOME << "/metamorphicCL/" << endl;
    out << "git clone https://github.com/mc-imperial/gpuverify.git GPUVerify" << endl;
    
    // metamorphiccl
    out << "cd " << HOME << "/metamorphicCL/" << endl;
    out << "git clone https://gitlab.doc.ic.ac.uk/multicore/metamorphiccl.git" << endl;
   
    out << "mkdir " << HOME << "/metamorphicCL/metamorphicCLbuild/" << endl;
    out << "cd " << HOME << "/metamorphicCL/metamorphicCLbuild/" << endl;
    out << "cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_CONFIG=./../llvm/build/bin/llvm-config " << HOME << "/metamorphicCL/metamorphiccl/libtooling/" << endl;
    out << "make -j" << MAKE_J << endl;
    
    // findtools
    ofstream ftools;
    ftools.open((HOME + "/metamorphicCL/metamorphiccl/python/findtools.py").c_str());
    ftools << "import sys" << endl;
    ftools << "rootDir = r\"" << HOME << "/metamorphicCL/\"" << endl;
    ftools << "metamorphicclDir = rootDir + r\"metamorphiccl/\"" << endl;
    ftools << "gpuverify = \"" << HOME << "/metamorphicCL/GPUVerify/\"" << endl;
    ftools << "sys.path.append(gpuverify)" << endl;
    ftools << "rewriterBinDir = rootDir + r\"metamorphicCLbuild/\"" << endl;
    ftools << "llvmBinDir = rootDir + r\"llvm/build/bin/\"" << endl;
    ftools << "spirToolsDir = rootDir + r\"spir/\"" << endl;
    
    
    out.close();
    
    return 0;
}