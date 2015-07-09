#!/usr/bin/python

import subprocess
import os

listFile = open('list.txt','r')

for programName in listFile:
    command = []
    command.append('/home/gj5/opencl/gvki-giulio-p/scripts/gvki.py')
    command.append('--verbose')
    command.append('--preprocess')
    command.append('--preload-library')
    command.append('/home/gj5/opencl/gvki-build/lib/libGVKI_preload.so')
    command.append('--working-dir')
    command.append('/home/gj5/opencl/AMDAPP/bin/')
    command.append('/home/gj5/opencl/AMDAPP/bin/x86_64/' + programName)
    print(command)
    subprocess.call(command)
    os.system("mv gvki-0 gvki-" + programName)