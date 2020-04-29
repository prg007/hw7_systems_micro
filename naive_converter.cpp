/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"
#include <stdlib.h>

int func( const char * str )
{
    int value = 0;
    while( *str )
    {
        value = value*10 + (*str++ - '0'); //Strategy here is to subtract the
    }                                      // Ascii value of the character with the
    return value;                          // Ascii value of '0' which corresponds to
}                                          // the given digit in numbers

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++)
  {
    nums[i] = func(lines[i]);
  }
}
