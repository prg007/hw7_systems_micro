/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"
#include <stdlib.h>

unsigned return_digit(char s)
{
   return unsigned(s - '0');
}

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  uint_fast32_t i = 0;
  unsigned d;
  while( i < nlines)
  {
    char const *str = lines[i];
    uint_fast32_t value = return_digit(*str);
    while ((d = return_digit(*++str)) <= 9)
    {
      value = value * 10 + d;
    }
    nums[i] = value;
    ++i;
  }
}
