#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "arena.h"

Arena arena_create()
{
   Arena a;
   a.capacity = ARENA_BUFFER_SIZE;
   a.buffers = 1;
   a.allocated = 0;

   a.buffer[0] = malloc(ARENA_BUFFER_SIZE);

   assert(a.buffer[0] != NULL);

   /* printf("Created Arena : %p\n", a.buffer[0]); */

   return a;
}

void arena_free(Arena* a)
{
   int i;
   /* printf("Free Arena\n"); */

   for (i = 0; i < a->buffers; ++i)
   {
      free(a->buffer[i]);
   }
}

void* arena_alloc(Arena* a, size_t count)
{
   char *ret;
   /*printf("Allocating %d bytes\n", count);*/
   assert(count < ARENA_BUFFER_SIZE);

   if (a->allocated + count > a->capacity)
   {
      assert(a->buffers + 1 <= ARENA_MAX_BUFFERS);
      a->buffers += 1;
      a->buffer[a->buffers - 1] = malloc(ARENA_BUFFER_SIZE),
      a->allocated = 0;
   }

   ret = a->buffer[a->buffers - 1];
   ret += a->allocated;
   /*ret += count;*/
   a->allocated += count;
   return ret;
}
