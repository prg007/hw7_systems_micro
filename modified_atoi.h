#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct modif_atoi
{
    modif_atoi(char* str) : str(str) {}
    operator uint32_t() const { return atoi(str); }
    private: char* str;
};

#undef uint32_t
#define uint32_t modif_atoi
