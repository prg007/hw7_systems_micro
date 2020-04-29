# hw7_systems_micro
This repository contains my homework files for systems

I,Prasun,worked alone on this project. To begin with running the original `converter.c` file on my machine gave me a <i>. Best run time overall: 0.053256s </i>

## Part 1
Before writing the naive version, I tried to identify the kernels in my program. I tried to make use of the profiler gprof as mentioned in the lectured notes by compiling with the -pg flag. Unfortunately, I got the error that MacOS doesn't support -pg flag beyond version 10.9. I then tried to make use of other profiling applications and stumbled across this StackOverFlow article.[Profiling techniques on MacOs](https://stackoverflow.com/questions/11445619/profiling-c-on-mac-os-x). It uses Instruments. After running Instruments on the original `converter.c` file I got the following results(look at the screenshot below, particularly on the right column - Heaviest Stack Trace). Inside the `convert_all` function, our stack trace has a value of 57826. Over, the next few approaches I tried to improve the stack trace inside the `convert_all` function. 
![Screenshot of running Instruments(profiler) on original converter.c file](https://github.com/prg007/hw7_systems_micro/blob/master/Screen%20Shot%202020-04-29%20at%204.17.16%20AM.png)

### Naive Version
- My naive version replaces the atoi with a custom function. My naive version gives <i> Best run time overall: 0.007619s </i>. I could have optimized my naive version further but I decided to trade it for readability instead and hold off further optimizations to the naive version until Part 2. My naive version is in the file `naive_converter.cpp`.  
- As to why it works better, I have the following explanation that many (if,else,branch,lots of cases,-ve numbers, retuens 0, no limit on the size(overflow) of the 
  - okay
