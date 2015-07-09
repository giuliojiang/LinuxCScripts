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
    command.append('/home/gj5/opencl/rodinia/rodinia_3.0/opencl/')
    command.append('/home/gj5/opencl/rodinia/rodinia_3.0/opencl/' + programName[:-1])
    joinedCommand = ' '.join(command)
    print(joinedCommand)
    cdInto = programName.rsplit('/',1)[0]
    # os.system('cd ' + cdInto + ' && ' + joinedCommand + ' && cd -')
    subprocess.call(['cd ' + cdInto + ' && ' + joinedCommand + ' && cd -'], shell=True)
    dirname = programName.split('/',1)[0]
    os.system("mv gvki-0 gvki-" + dirname)
    
os.system('mv gvki-1 gvki-particlefilter-1')