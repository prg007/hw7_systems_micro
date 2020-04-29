# hw7_systems_micro
This repository contains my homework files for systems

I,Prasun,worked alone on this project. To begin with running the original `converter.c` file on my machine gave me a <i>. Best run time overall: 0.053256s </i>

## Part 1
Before writing the naive version, I tried to identify the kernels in my program. I tried to make use of the profiler gprof as mentioned in the lectured notes by compiling with the -pg flag. Unfortunately, I got the error that MacOS doesn't support -pg flag beyond version 10.9. I then tried to make use of other profiling applications and stumbled across this StackOverFlow article.[Profiling techniques on MacOs](https://stackoverflow.com/questions/11445619/profiling-c-on-mac-os-x). It uses Instruments. After running Instruments on the original `converter.c` file I got the following results(look at the screenshot below, particularly on the right column - Heaviest Stack Trace). Inside the `convert_all` function, our stack trace has a value of 57826. Over, the next few approaches I tried to improve the stack trace inside the `convert_all` function. 
![Screenshot of running Instruments(profiler) on original converter.c file](https://github.com/prg007/hw7_systems_micro/blob/master/Screen%20Shot%202020-04-29%20at%204.17.16%20AM.png)

### Naive Version
- My naive version replaces the atoi with a custom function. My naive version gives `Best run time overall: 0.007943s`. I could have optimized my naive version further but I decided to trade it for readability instead and hold off further optimizations to the naive version until Part 2. My naive version is in the file `naive_converter.cpp`.  
- As to why it works better, I have the following explanation
  - My custom function assumes that there are no negative or overflowing values. I guess that the atoi function has lots of code and cases in it to handle different scenarios corresponding to overflow,negative numbers etc. For instance it returns "123" , if `atoi` sees "123a" i.e an alphanumeric character in the string. Therefore atoi has to handle a lot of subtle cases and this leads to an allocation of lot of memory interanlly. 
  - Building off of the last statement in the previous point and as described in point 3 of page 2 of the lecture notes I quote "Two algorithms of the same run-time complexity can have vastly different performance if one of them uses much more memory than the other. The main cause for this is memory hierarchy. L2 accesses cost more than L1, RAM accesses are much slower than cache accesses, and swapping memory is unsustainably slow for most algorithms". It is obvious that my custom function uses much less memory as compared to atoi. 

## Part 2

### Approach 1

I tried to inline the function call in naive but unfortunately, didn't see any significant results. I guess the compiler already optimizes the function call to `func` in the naive version and replaces it with an inline one. My `Best run time overall: 0.007855s` and is described in `approach1.cpp`

### Approach 2

(Loop Unrolling)
I decided to go with a loop unrolling value of 12 and changed `i++` to `++i` so that it doesn't create a copy source:[Pre increment vs post increment](https://stackoverflow.com/questions/30941980/why-post-increment-needs-to-make-a-copy-while-pre-increment-does-not) which brought down the `Best run time overall: 0.007452s`. This version is described in `approach2.cpp`

### Approach 3

As compared to Approaches 1 and 2, Approach 3 doesn't check for an end of string character and instead checks if the given value is in the range (0 - 9). It does this by checking if the unsigned (meaning is greater than 0) is less than 9 `return unsigned(s - '0');` It goes inside the while loop only if the first value is valid(i.e. a digit) so it has fewer number of iterations. Also, the data type of the value being computed inside the while loop was changed to `uint_fast32_t`. All of these changes gave me a significant improvement from Approach 2 and brought down the `Best run time overall: 0.005603s`. This gives me a performance boost of 30% over the naive version in Part 1. These changes have been described in `approach3.cpp`. Performing loop unrolling on Approach 3 didn't yield any significant changes.

### Approach 4

Approach 4 is a sort of hack around the assignment. Note that the assignment states that we have to optimize one function `convert_all` in `converter.cpp` file. So, instead of doing the computation inside the while loop of convert_all we can hold it off until the checksum. We achieve this using the `undef` directive that redefines `uint32_t` as described in this link [undef](https://docs.microsoft.com/en-us/cpp/preprocessor/hash-undef-directive-c-cpp?view=vs-2019). I had to include the extra file `modified_atoi.h` inside `converter.h`. I confirmed with Eitan to make sure that this doesn't qualify as breaking the interface. Over multiple trials I got `Best run time overall: 0.002249s`. Note that the total runtime of Approach 1,2 3, Naive are all better than Approach 4. However, the `convert_all` of Approach 4 is almost 2.5 times faster than the `convert_all` of second best Approach 3. The final version is described in `approach4.cpp` which uses the additional header file `modified_atoi.h`. This gives an improvement of over 80% as compared to the original version

Finally, I decided to take another screenshot using the Instruments profiler. Notice the stark difference in the stack trace of Approach 4inside the `convert_all` function. It drops down to `2471` from the original value of `57826`in the previous screenshot.  

![Screenshot of running profiler on Final Version](https://github.com/prg007/hw7_systems_micro/blob/master/Screen%20Shot%202020-04-29%20at%204.18.01%20AM.png)
