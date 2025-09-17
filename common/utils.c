#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "conio.h"
#include "utils.h"

float map(float value, float minin, float maxin, float minout, float maxout)
{
   return minout + (value - minin) / (maxin - minin) * (maxout - minout);
}

float clamp(float value, float minimum, float maximum)
{
   return min(max(value, minimum), maximum);
}

bool ends_with(const char* str, const char* substr)
{
   int i;
   int lenOfStr = strlen(str);
   int lenOfSubstr = strlen(substr);

   if (lenOfSubstr > lenOfStr)
   {
      return false;
   }

   for (i = 0; i < lenOfSubstr; i++)
   {
      if (str[i + lenOfStr - lenOfSubstr] != substr[i])
      {
         return false;
      }
   }

   return true;
}

int gcd(int a, int b)
{
  if (b > a)
  {
    return gcd(b, a);
  }

  if (b == 0)
  {
    return a;
  }

  return gcd(b, a % b);
}

void wait_for_key(void)
{
  char ch;
  while (!kbhit()) {}
  ch = getch();
  if (ch == 0)
  {
    ch = getch();
  }
}
