#ifndef _ECODES_H_
#define _ECODES_H_

#include "arena.h"

#define MAX_LINES 200

typedef struct {
  int count;
  char* line[MAX_LINES];
} Lines;

void print_title(const char* title, const char* subtitle);
void start_part(int part);
Lines read_file_lines(const char* filename, Arena* arena);

#endif

