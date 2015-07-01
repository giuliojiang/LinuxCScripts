# LinuxCScripts
Automation scripts

```

BatchRunGVKI
takes 1 command line argument: the path of the exectables
and reads from stdin the names of the executables to launch.
By running LD_PRELOAD=[path_to_gvki_preload.so] ./automate <PathToExecutables> < input_list.txt
will batch run all the executables in the list and create appropriately named gvki folders.

```
