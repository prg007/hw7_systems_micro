/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void convert_all(unsigned nlines, char* lines[], quote_t nums[])
{
    for (unsigned i = 0; i < nlines; ++i)
    {
        nums[i] = *(new modif_atoi(lines[i]));
    }
}
