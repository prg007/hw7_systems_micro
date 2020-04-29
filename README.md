# hw7_systems_micro
This repository contains my homework files for systems

I,Prasun,worked alone on this project. To begin with running the original `converter.c` file on my machine gave me a <i>. Best run time overall: 0.053256s </i>

## Part 1
Before writing the naive version, I tried to identify the kernels in my program. I tried to make use of the profiler gprof as mentioned in the lectured notes by compiling with the -pg flag. Unfortunately, I got the error that MacOS doesn't support -pg flag beyond version 10.9. I then tried to make use of other profiling applications and stumbled across this StackOverFlow article.[Profiling techniques on MacOs](https://stackoverflow.com/questions/11445619/profiling-c-on-mac-os-x). It uses Instruments. After running Instruments on the original `converter.c` file I got the following results(look at the screenshot below, particularly on the right column - Heaviest Stack Trace). Inside the `convert_all` function, our stack trace has a value of 57826. Over, the next few approaches I tried to improve the stack trace inside the `convert_all` function. 
![Screenshot of running Instruments(profiler) on original converter.c file](https://github.com/prg007/hw7_systems_micro/blob/master/Screen%20Shot%202020-04-29%20at%204.17.16%20AM.png)

### Naive Version
- My naive version replaces the atoi with a custom function. My naive version gives <i> Best run time overall: 0.007619s </i>. I could have optimized my naive version further but I decided to trade it for readability instead and hold off further optimizations to the naive version until Part 2. My naive version is in the file `naive_converter.cpp`.  
- As to why it works better, I have the following explanation
  - My custom function assumes that there are no negative or overflowing values. I guess that the atoi function has lots of code and cases in it to handle different scenarios corresponding to overflow,negative numbers etc. For instance it returns "123" , if `atoi` sees "123a" i.e an alphanumeric character in the string. Therefore atoi has to handle a lot of subtle cases and this leads to an allocation of lot of memory interanlly. 
  - Building off of the last statement in the previous point and as described in point 3 of page 2 of the lecture notes I quote "Two algorithms of the same run-time complexity can have vastly different performance if one of them uses much more memory than the other. The main cause for this is memory hierarchy. L2 accesses cost more than L1, RAM accesses are much slower than cache accesses, and swapping memory is unsustainably slow for most algorithms". It is obvious that my custom function uses much less memory as compared to atoi. 

## Part 2

### Approach 1

I tried to inline the function call to naive but unfortunately, didn't see any significant results. I guess the compiler already optimizes the function call to `func` in the naive version and replaces it with an inline one. My <i>Best run time overall: 0.007655s</i> and is described in approach1.cpp
