#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "ansi.h"
#include "utils.h"
#include "arena.h"
#include "ecodes.h"
#include "da.h"

/* https://everybody.codes/story/2/quests/2 */

#define NAME     "E2Q01"
#define TITLE    "The Entertainment Hub [ No. 2 ]"
#define SUBTITLE "Quest 1: Nail Down Your Luck   "

#define PART1FILE "E2Q01P1.TXT"
#define XPART1FILE "E2Q01P1_.TXT"
/* Test Result = 26 */

#define PART2FILE "E2Q01P2.TXT"
#define XPART2FILE "E2Q01P2_.TXT"
/* Test Result = 115 */

#define XPART3FILE "E2Q01P3.TXT"
#define PART3FILE "E2Q01P3_.TXT"
/* Test Result = 39 122 */

Arena arena;

int drop_peg(int toss_slot, int move_index, int board_lines, Lines* data)
{
  int final_slot, score;
  int x, y, mix;
  char c;
  const char* moves = data->line[move_index];
  int board_width = strlen(data->line[0]);
  /*
  printf("Drop in slot %s%d%s with moves %s%s%s -> ", YELLOW BOLD, toss_slot, RESET, BOLD, moves, RESET);
  */

  x = toss_slot * 2 - 1 - 1;
  y = 0;
  mix = 0;
  while (y < board_lines)
  {
    if (moves[mix] == 'R')
    {
      x++;
      if (x >= board_width)
      {
	x -= 2;
      }
    }
    else if (moves[mix] == 'L')
    {
      x--;
      if (x < 0)
      {
	x += 2;
      }
    }
    else
    {
      return -1000;
    }

    mix++;
    y += 1;
    c = data->line[y][x];
    while (c != '*')
    {
      y++;
      if (y >= board_lines)
      {
	break;
      }
      c = data->line[y][x];
    }
  }

  final_slot = (x + 1 + 1) / 2;
  score = max(0, (final_slot * 2) - toss_slot);
  /*
  printf("%s%d%s", BOLD YELLOW, final_slot, RESET);
  printf(" = %s%d%s\n", BOLD GREEN, score, RESET);
  */
  return score;
}

int part1(void)
{
  int board_lines;
  int move_lines, first_move_line;

  int i, score = 0;
  Lines data;

  start_part(1);

  data = read_file_lines(PART1FILE, &arena);
  for (i = 0; i < data.count; ++i)
  {
    if (strlen(data.line[i]) == 0)
    {
      board_lines = i;
      first_move_line = i + 1;
      move_lines = data.count - board_lines - 1;
    }
  }

  /*
  printf("Board Lines: %d\n", board_lines);
  printf("Move Lines: %d\n", move_lines);
  printf("First Move Line: %d\n", first_move_line);
  */

  for (i = first_move_line; i < data.count; ++i)
  {
    score += drop_peg(i - first_move_line + 1, i, board_lines, &data);
  }

  printf("\nTotal Score: %s%d%s\n", BOLD GREEN, score, RESET);
}

int part2(void)
{
  int board_lines;
  int move_lines, first_move_line;

  int i, score = 0, highest, this_score;
  Lines data;
  int slot_count, slot;

  start_part(2);

  data = read_file_lines(PART2FILE, &arena);
  for (i = 0; i < data.count; ++i)
  {
    if (strlen(data.line[i]) == 0)
    {
      board_lines = i;
      first_move_line = i + 1;
      move_lines = data.count - board_lines - 1;
    }
  }

  /*
  printf("Board Lines: %d\n", board_lines);
  printf("Move Lines: %d\n", move_lines);
  printf("First Move Line: %d\n", first_move_line);
  */

  slot_count = (strlen(data.line[0]) + 1) / 2;

  for (i = first_move_line; i < data.count; ++i)
  {
    highest = 0;
    for (slot = 1; slot <= slot_count; ++slot)
    {
      this_score = drop_peg(slot, i, board_lines, &data);
      highest = max(highest, this_score);
    }

    score += highest;
  }

  printf("\nTotal Score: %s%d%s\n", BOLD GREEN, score, RESET);
}

int part3(void)
{
  int board_lines;
  int move_lines, first_move_line;

  int i, min_score = 0, max_score = 0;
  int highest, this_score;
  Lines data;
  int slot_count, slot;

  start_part(3);

  data = read_file_lines(PART3FILE, &arena);
  for (i = 0; i < data.count; ++i)
  {
    if (strlen(data.line[i]) == 0)
    {
      board_lines = i;
      first_move_line = i + 1;
      move_lines = data.count - board_lines - 1;
    }
  }

  /*
  printf("Board Lines: %d\n", board_lines);
  printf("Move Lines: %d\n", move_lines);
  printf("First Move Line: %d\n", first_move_line);
  */

  slot_count = (strlen(data.line[0]) + 1) / 2;

  /*
  20 choose 6
  C(n,k) = n! / (k! * (n-k)!)
  =38760
  */

  /* TODO */
  for (i = first_move_line; i < data.count; ++i)
  {
    for (slot = 1; slot <= slot_count; ++slot)
    {
      this_score = drop_peg(slot, i, board_lines, &data);
    }
  }

  printf("\nFinal answer: %s%d %d%s\n", BOLD GREEN, min_score, max_score, RESET);
}

int main(void)
{
  print_title(TITLE, SUBTITLE);

  arena = arena_create();

  part1();
  part2();
  part3();

  arena_free(&arena);

  wait_for_key();
  return 0;
}
