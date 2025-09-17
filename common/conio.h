#ifndef _CONIO_H_
#define _CONIO_H_

enum CURSORTYPE
{
  NOCURSOR,      // turns off the cursor
  SOLIDCURSOR,   // solid block cursor
  NORMALCURSOR   // normal underscore cursor
};

struct text_info
{
  unsigned char attribute;      /* text attribute */
  unsigned char normattr;       /* normal attribute */
  int screenheight;   /* text screen's height */
  int screenwidth;    /* text screen's width */
  int curx;           /* x-coordinate in current window */
  int cury;           /* y-coordinate in current window */
};

int   getch(void);
int   getche(void);
int   kbhit(void);

void  clrscr();
void  gotoxy(int x, int y);
void  setcursortype(int cur_t);
int   wherex(void);
int   wherey(void);
void  gettextinfo(struct text_info *r);
void  textattr(int newattr);

#endif

