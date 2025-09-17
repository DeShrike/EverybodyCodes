#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "conio.h"

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}


static int getCursorPosition2(int *x, int *y)
{
  *x = -1;
  *y = -1;

  char buf[32];
  unsigned int i = 0;
  int ch;

  printf("\x1B[6n");

  while (i < sizeof(buf) - 1)
  {
    ch = getch();
    if (ch == EOF || ch == 'R') break;
    buf[i++] = ch;
  }

  buf[i] = '\0';

  if (buf[0] != '\x1b' || buf[1] != '[') return -1;

  if (sscanf(&buf[2], "%d;%d", y, x) != 2) return -1;

  return 0;
}

int wherex(void)
{
  int x, y;
  getCursorPosition2(&x, &y);
  return x;
}

int wherey(void)
{
  int x, y;
  getCursorPosition2(&x, &y);
  return y;
}


void gotoxy(int x, int y)
{
  printf("\x1b[%d;%dH", y, x);
  fflush(stdout);
}

void clrscr()
{
  puts("\x1b[2J\x1b[1;1H");
  fflush(stdout);
}

int getch(void)
{
  struct termios old, znew;
  int ch;

  tcgetattr(0, &old);

  znew = old;
  znew.c_lflag &= ~ICANON;
  znew.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &znew);

  ch = getchar();

  tcsetattr(0, TCSANOW, &old);

  return ch;
}

int getche(void)
{
  struct termios old, znew;
  int ch;

  tcgetattr(0, &old);

  znew = old;
  znew.c_lflag &= ~ICANON;
  //znew.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &znew);

  ch = getchar();

  tcsetattr(0, TCSANOW, &old);
  return ch;
}

void setcursortype(int cur_t)
{
  switch (cur_t)
  {
  case NOCURSOR:
    printf("\x1b[?25l");
    break;

  case NORMALCURSOR:
    printf("\x1b[?25h");
    break;

  case SOLIDCURSOR:  // TODO
    printf("\x1b[?25h");
    break;
  }
}

void gettextinfo(struct text_info *r)
{
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  r->screenheight = w.ws_row;
  r->screenwidth = w.ws_col;

  int x, y;
  getCursorPosition2(&x, &y);

  r->curx = x;
  r->cury = y;
}
