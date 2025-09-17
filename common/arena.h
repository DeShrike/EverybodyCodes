#ifndef _ARENA_H_
#define _ARENA_H_

#define ARENA_BUFFER_SIZE  5 * 1024
#define ARENA_MAX_BUFFERS  16

typedef struct {
   void* buffer[ARENA_MAX_BUFFERS];
   size_t capacity;
   size_t allocated;
   int buffers;
} Arena;

Arena arena_create();
void arena_free(Arena* a);
void* arena_alloc(Arena* a, size_t bytes);

#endif
