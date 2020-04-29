# hw7_systems_micro
This repository contains my homework files for systems

I,Prasun,worked alone on this project. To begin with running the original 'converter.c' file on my machine gave me a <i>. Best run time overall: 0.053256s </i>

## Part 1
Before writing the naive version, I tried to identify the kernels in my program. I tried to make use of the profiler gprof as mentioned in the lectured notes by compiling with the -pg flag. Unfortunately, I got the error that MacOS doesn't support -pg flag beyond version 10.9. I then tried to make use of other profiling applications and stumbled across this StackOverFlow article.[Profiling techniques on MacOs](https://stackoverflow.com/questions/11445619/profiling-c-on-mac-os-x). It uses Instruments. After running Instruments on the original 'converter.c' file I got the following results
