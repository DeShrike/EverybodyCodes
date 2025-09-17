#include <assert.h>
#include <dos.h>
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

char *args_shift(int *argc, char ***argv)
{
   char *result = NULL;

   assert(*argc > 0);
   *result = (char*)**argv;
   (*argc) -= 1;
   (*argv) += 1;
   return result;
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

void print_memory(void)
{
  struct SREGS sregs;
  union REGS regs;
  regs.h.ah = 0x48;
  int86x(0x21, &regs, &regs, &sregs);
  printf("Total memory: %dKB\n", regs.x.bx);
  printf("Free memory: %dKB\n", biosmemory());
}

void print_roman_year(int year)
{
  char *u[]={"I","II","III","IV","V","VI","VII","VIII","IX","X"};
  char *t[]={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C"};
  char *h[]={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M"};
  int i, j, k, l, temp;

  if (year >= 9999 || year < 1)
  {
    return;
  }

  i = year % 10;
  temp = year - i;
  j = temp % 100;
  temp = temp - j;
  k = temp % 1000;
  temp = temp - k;
  for (l = 1000; l <= temp; l = l + 1000)
  {
    putchar('M');
  }

  k = k / 100;
  j = j / 10;
  if (k != 0) printf("%s", h[k - 1]);
  if (j != 0) printf("%s", t[j - 1]);
  if (i != 0) printf("%s", u[i - 1]);
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

