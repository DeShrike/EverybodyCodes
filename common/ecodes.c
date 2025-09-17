#include <stdio.h>
#include "ansi.h"
#include "ecodes.h"

void print_title(const char* title, const char* subtitle)
{
  printf("%s%s%s %s %s\n", BlueBackground, BOLD, WHITE, title, RESET);
  printf("%s%s %s %s\n", BlueBackground, CYAN, subtitle, RESET);
}

void start_part(int part)
{
  printf("\n%s%s%s Part %d %s\n\n", MagentaBackground, WHITE, BOLD, part, RESET);
}

Lines read_file_lines(const char* filename, Arena* arena)
{
  FILE* fp;
  char buffer[1000];
  int l, i;

  Lines lines;
  lines.count = 0;
  for (i = 0; i < MAX_LINES; ++i)
  {
    lines.line[i] = NULL;
  }

  printf("Reading file %s%s%s ...", BOLD, filename, RESET);

  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    perror("FAIL: ");
    return lines;
  }

  while (fgets(buffer, 1000, fp))
  {
    buffer[strcspn(buffer, "\n")] = 0;
    l = strlen(buffer);
    lines.line[lines.count] = arena_alloc(arena, l + 3);
    strcpy(lines.line[lines.count], buffer);
    lines.count++;
    if (lines.count == MAX_LINES)
    {
      break;
    }
  }

  fclose(fp);

  printf(" %s%s%d%s lines.\n", YELLOW, BOLD, lines.count, RESET);

  return lines;
}
