#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include "combinations.h"

// Recursive function to generate combinations
static bool generate_combinations(int arr[], int data[], size_t start, size_t end, int index, int r,
                          combinations_callback process, void* ctx)
{
    // Base case: if r elements are selected, print the combination
    if (index == r)
    {
        assert(ctx != NULL);
        if (!process(data, r, ctx))
        {
           return false;
        }

        return true;
    }

    // Iterate through the remaining elements
    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        // Include the current element in the combination
        data[index] = arr[i];

        // Recur for the next element
        generate_combinations(arr, data, i + 1, end, index + 1, r, process, ctx);
    }
    
    return true;
}

// Function to initiate the combination generation
bool combinations(int arr[], size_t x, size_t y, combinations_callback process, void* ctx)
{
   assert(y > 0);
   assert(y <= x);

   int data[y]; // Array to store the current combination
   if (!generate_combinations(arr, data, 0, x - 1, 0, y, process, ctx))
   {
      return false;
   }
}


#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combinations.h"

typedef struct {
  int count;
  char* msg;
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

int main()
{
   //int arr[] = {1, 2, 3, 4, 5, 6};
   //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
   size_t x = sizeof(arr) / sizeof(arr[0]);
   size_t y = 10;

   printf("Combinations of %d elements taken %d at a time:\n", x, y);

   Ctx data = {0};
   data.msg = "Combinations";

   combinations(arr, x, y, &process, &data);

   printf("Combinations of %d elements taken %d at a time:\n", x, y);
   printf("There are %d combinations\n", data.count);

   return 0;
}

#endif
