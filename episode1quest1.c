#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "conio.h"
#include "ansi.h"
#include "utils.h"
#include "arena.h"
#include "ecodes.h"
#include <limits.h>

/* https://everybody.codes/story/1/quests/1 */

#define NAME     "E1Q1"
#define TITLE    "Echoes of Enigmatus [ No. 1 ]"
#define SUBTITLE "Quest 1: EniCode             "

#define PART1FILE "./data/everybody_codes_e1_q01_p1.txt"
#define XPART1FILE "./data/everybody_codes_e1_q01_p1_test1.txt"
/* Test 1 Result = 11611972920 */

#define XPART2FILE "./data/everybody_codes_e1_q01_p2.txt"
#define XXPART2FILE "./data/everybody_codes_e1_q01_p2_test1.txt"
/* Test 1 Result = 11051340 */
#define PART2FILE "./data/everybody_codes_e1_q01_p2_test2.txt"
/* Test 2 Result = 1507702060886 */


#define PART3FILE "./data/everybody_codes_e1_q01_p3.txt"
#define XXXPART3FILE "./data/everybody_codes_e1_q01_p3_test1.txt"
/* Test 1 Result = 13 43 */
#define XXPART3FILE "./data/everybody_codes_e1_q01_p3_test2.txt"
/* Test 2 Result = 25 66 */
#define XPART3FILE "./data/everybody_codes_e1_q01_p3_test3.txt"
/* Test 3 Result = 39 122 */

Arena arena;

typedef struct {
   long a, b, c;
   long x, y, z;
   long m;
} Params;

Params parse_line(const char* line)
{
   Params p = {0};

   sscanf(line, "A=%ld B=%ld C=%ld X=%ld Y=%ld Z=%ld M=%ld",
      &p.a, &p.b, &p.c,
      &p.x, &p.y, &p.z,
      &p.m);

   return p;
}

long f_eni(long n, long exp, long mod)
{
   char temp[1000];
   char result[1000];
   long score = 1;
   long rem;
   result[0] = 0;
   for (int i = 0; i < exp; ++i)
   {
      score *= n;
      rem = score % mod;
      sprintf(temp,"%ld", rem);
      strcat(temp, result);
      strcpy(result, temp);
   }
   
   return atol(result);
}

long f_eni2(long n, long exp, long mod)
{
   // printf("%ld %ld %ld -> \n", n, exp, mod);

   char temp[1000];
   char result[1000];
   long score = 1;
   long rem[5] = {0};
   long shifts = 0;
   result[0] = 0;
   for (int i = 0; i < exp; ++i)
   {
      score *= n;

      shifts++;
      for (int j = 3; j >= 0; --j)
      {
         rem[j + 1] = rem[j];
      }
      
      rem[0] = score % mod;

      /*
      for (int j = 0; j < 5; ++j)
      {
         printf("%ld ", rem[j]);
      }

      printf("\n"); */
   }

   for (int i = 0; i < min(shifts, 5); ++i)
   {
      sprintf(temp,"%ld", rem[i]);
      strcat(result, temp);
   }

   // printf("%s\n", result);
   // wait_for_key();
   return atol(result);
}

/*
   // reverse it
   char *s = result;
   char *e = result + strlen(result) - 1;
   while (e >= s)
   {
      char t = *s;
      *s = *e;
      *e = t;
      e--;
      s++;
   }
*/

void part1(void)
{
   start_part(1);

   Lines data = read_file_lines(PART1FILE, &arena);
   if (data.count == 0)
   {
      printf("No lines read\n");
      return;
   }

   Params params[data.count];
   int params_count = data.count;
   
   for (int i = 0; i < data.count; ++i)
   {
      Params p = parse_line(data.line[i]);
      params[i] = p;
   }

   long highest = 0;
   for (int i = 0; i < params_count; ++i)
   {
      printf("A=%ld B=%ld C=%ld X=%ld Y=%ld Z=%ld M=%ld > ",
         params[i].a, params[i].b, params[i].c,
         params[i].x, params[i].y, params[i].z,
         params[i].m);
      long sum = f_eni(params[i].a, params[i].x, params[i].m) +
                 f_eni(params[i].b, params[i].y, params[i].m) +
                 f_eni(params[i].c, params[i].z, params[i].m);
      printf("%s%ld%s\n", YELLOW BOLD, sum, RESET);
      if (sum > highest)
      {
         highest = sum;
      }

      // printf("eni(%d,%d,%d) = %ld\n", params[i].a, params[i].x, params[i].m, f_eni(params[i].a, params[i].x, params[i].m));
      // printf("eni(%d,%d,%d) = %ld\n", params[i].b, params[i].y, params[i].m, f_eni(params[i].b, params[i].y, params[i].m));
      // printf("eni(%d,%d,%d) = %ld\n", params[i].c, params[i].z, params[i].m, f_eni(params[i].c, params[i].z, params[i].m));
   }

   printf("\nHighest number: %s%ld%s\n", BOLD GREEN, highest, RESET);
}

void part2(void)
{
   start_part(2);

   Lines data = read_file_lines(PART2FILE, &arena);
   if (data.count == 0)
   {
      printf("No lines read\n");
      return;
   }

   Params params[data.count];
   int params_count = data.count;
   
   for (int i = 0; i < data.count; ++i)
   {
      Params p = parse_line(data.line[i]);
      params[i] = p;
   }

   /*
   long highest = 0;
   for (int i = 0; i < params_count; ++i)
   {
      printf("A=%ld B=%ld C=%ld X=%ld Y=%ld Z=%ld M=%ld > ",
         params[i].a, params[i].b, params[i].c,
         params[i].x, params[i].y, params[i].z,
         params[i].m);
      fflush(stdout);
      long sum = f_eni2(params[i].a, params[i].x, params[i].m) +
                 f_eni2(params[i].b, params[i].y, params[i].m) +
                 f_eni2(params[i].c, params[i].z, params[i].m);
      printf("%s%ld%s\n", YELLOW BOLD, sum, RESET);
      if (sum > highest)
      {
         highest = sum;
      }

      // printf("eni(%ld,%ld,%ld) = %ld\n", params[i].a, params[i].x, params[i].m, f_eni2(params[i].a, params[i].x, params[i].m));
      // printf("eni(%ld,%ld,%ld) = %ld\n", params[i].b, params[i].y, params[i].m, f_eni2(params[i].b, params[i].y, params[i].m));
      // printf("eni(%ld,%ld,%ld) = %ld\n", params[i].c, params[i].z, params[i].m, f_eni2(params[i].c, params[i].z, params[i].m));
   }

   printf("\nHighest number: %s%ld%s\n", BOLD GREEN, highest, RESET);
   */
/*
   long xx = f_eni2(2, 7, 5);
   printf(" = %ld\n", xx);

   xx = f_eni2(4, 3, 11);
   printf(" = %ld\n", xx);

   xx = f_eni2(4, 14, 11);
   printf(" = %ld\n", xx);
*/

   long a = 903056852;
   long x = 188;
   long d = gcdl(a, x);
   printf("gcd(%ld,%ld) = %ld\n", a, x, d);

   a = 9283895500;
   x = 188;
   d = gcdl(a, x);
   printf("gcd(%ld,%ld) = %ld\n", a, x, d);

   a = 85920867478;
   x = 188;
   d = gcdl(a, x);
   printf("gcd(%ld,%ld) = %ld\n", a, x, d);

   printf("\n");

   printf("LONG_MAX: %ld\n", LONG_MAX);
}

void part3(void)
{
  start_part(3);
}

int main(void)
{
  print_title(TITLE, SUBTITLE);

  arena = arena_create();

  part1();
  part2();
  part3();

  arena_free(&arena);

  // wait_for_key();
  return 0;
}
