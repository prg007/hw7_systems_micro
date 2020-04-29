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
  uint_fast32_t i = 0;
  while( i < nlines)
  {
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
      nums[i] = func(lines[i]);
      ++i;
  }
}
