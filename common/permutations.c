#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include "permutations.h"

static void swap(int* elements, size_t a, size_t b)
{
  int tmp = elements[a]; elements[a] = elements[b]; elements[b] = tmp;
}

static void flip(int* elements, size_t lo, size_t hi)
{
   for (; lo + 1 < hi; ++lo, --hi) swap(elements, lo, hi - 1);
}

static void rotate_left(int* elements, size_t lo, size_t hi)
{
  if (hi > lo)
  {
    int tmp = elements[lo];
    for (size_t i = lo + 1; i < hi; ++i)
    {
      elements[i - 1] = elements[i];
    }

    elements[hi - 1] = tmp;
  }
}

/* Recursive function; the main function will fill in the extra parameters */
/* Requires hi >= lo and hi >= k. Array must have size (at least) lo + k */
static bool helper(int* array, size_t lo, size_t k, size_t hi, permutation_callback process, void* ctx)
{
   if (hi == lo)
   {
      assert(ctx != NULL);
      if (!process(array + lo, k, ctx))
      {
         return false;
      }

      if (lo % 2)
      {
         flip(array, 0, lo);
      }
      else
      {
         rotate_left(array, 0, lo);
      }
   }
   else
   {
      for (size_t i = 0; i < hi - 1; ++i)
      {
         if (!helper(array, lo, k, hi - 1, process, ctx))
         {
            return false;
         }

         swap(array, hi % 2 ? 0 : i, hi - 1);
      }

      if (!helper(array, lo, k, hi - 1, process, ctx))
      {
         return false;
      }
   }

   return true;
}

/* Generate all k-permutations of the given array of size n.
 * The process function is called with each permutation; if it returns false,
 * generation of permutations is terminated.
 */
bool permutations(int* array, size_t n, size_t k, permutation_callback process, void* ctx)
{
  assert(k <= n);
     // TODO asert there is a callback
  return helper(array, n - k, k, n, process, ctx);
}


#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "permutations.h"

typedef struct {
   char* msg;
   int count;
} Ctx;

bool process(int elements[], size_t n, void* ctx)
{
   Ctx* data = (Ctx*)ctx;
/*   printf("[%s] ", data->msg);
   for (size_t i = 0; i < n; ++i)
   {
      printf("%d ", elements[i]);
   }

   printf("\n");*/

   data->count++;
   return true;
}

int main(int argc, char** argv)
{
   //int arr[] = {1, 2, 3, 4, 5, 6};
   //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
   size_t n = sizeof(arr) / sizeof(arr[0]);
   size_t k = 6;

   printf("Permutations of %d elements taken %d at a time:\n", n, k);

   Ctx data = {0};
   data.msg = "Permutations";

   permutations(arr, n, k, process, &data);

   printf("Permutations of %d elements taken %d at a time:\n", n, k);
   printf("There are %d permutations\n", data.count);

   return 0;
}

#endif
