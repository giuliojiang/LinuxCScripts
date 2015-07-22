#!/usr/bin/python

import subprocess
import os

#You should copy this script and list.txt inside AMDAPP/bin directory and
#run it from there.

gvkiWrapperScript = '/home/gj5/ocl/gvki-ic/scripts/gvki.py'
gvkiPreloadLibrary = '/home/gj5/ocl/gvki-build/lib/libGVKI_preload.so'
gvkiWorkingDirectory = '/home/gj5/ocl/shocbin/bin/Serial/'
amdBinx86Directory = '/home/gj5/ocl/shocbin/bin/Serial/OpenCL/'

listFile = open('/home/gj5/ocl/LinuxCScripts/BatchRunGVKI/shoc/list.txt','r')

for programName in listFile:
    os.chdir(gvkiWorkingDirectory)
    command = []
    command.append(gvkiWrapperScript)
    # command.append('--verbose')
    command.append('--preprocess')
    command.append('--preload-library')
    command.append(gvkiPreloadLibrary)
    command.append('--working-dir')
    command.append(gvkiWorkingDirectory)
    command.append(amdBinx86Directory + programName)
    print(command)
    subprocess.call(command)
    os.system("mv gvki-0 gvki-" + programName)