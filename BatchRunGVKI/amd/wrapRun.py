#!/usr/bin/python

import subprocess
import os

#You should copy this script and list.txt inside AMDAPP/bin directory and
#run it from there.

gvkiWrapperScript = '/home/gj5/ocl/gvki-giulio-p/scripts/gvki.py'
gvkiPreloadLibrary = '/home/gj5/ocl/gvki-build/lib/libGVKI_preload.so'
gvkiWorkingDirectory = '/home/gj5/ocl/AMD_benchmarks/opencl/bin/'
amdBinx86Directory = '/home/gj5/ocl/AMD_benchmarks/opencl/bin/x86_64/'

listFile = open('list.txt','r')

os.chdir(amdBinx86Directory)

for programName in listFile:
    command = []
    command.append(gvkiWrapperScript)
    command.append('--verbose')
    command.append('--preprocess')
    command.append('--preload-library')
    command.append(gvkiPreloadLibrary)
    command.append('--working-dir')
    command.append(gvkiWorkingDirectory)
    command.append(amdBinx86Directory + programName)
    print(command)
    subprocess.call(command)
    subprocess.call(['mv', os.path.abspath(gvkiWorkingDirectory + os.sep + 'gvki-0'), os.path.abspath(gvkiWorkingDirectory + os.sep + 'gvki-' + programName)])