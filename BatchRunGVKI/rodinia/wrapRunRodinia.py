#!/usr/bin/python

import subprocess
import os

# copy this script and list.txt inside rodinia/opencl
# and run it from there

gvkiWrapperScript = '/home/gj5/opencl/gvki-giulio-p/scripts/gvki.py'
gvkiPreloadLibrary = '/home/gj5/opencl/gvki-build/lib/libGVKI_preload.so'
gvkiWorkingDirectory = '/home/gj5/opencl/rodinia/rodinia_3.0/opencl/'

listFile = open('list.txt','r')

for programName in listFile:
    command = []
    command.append(gvkiWrapperScript)
    command.append('--verbose')
    command.append('--preprocess')
    command.append('--preload-library')
    command.append(gvkiPreloadLibrary)
    command.append('--working-dir')
    command.append(gvkiWorkingDirectory)
    command.append(gvkiWorkingDirectory + programName[:-1])
    joinedCommand = ' '.join(command)
    print(joinedCommand)
    cdInto = programName.rsplit('/',1)[0]
    # os.system('cd ' + cdInto + ' && ' + joinedCommand + ' && cd -')
    subprocess.call(['cd ' + cdInto + ' && ' + joinedCommand + ' && cd -'], shell=True)
    dirname = programName.split('/',1)[0]
    os.system("mv gvki-0 gvki-" + dirname)
    
os.system('mv gvki-1 gvki-particlefilter-1')