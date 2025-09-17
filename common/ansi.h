#ifndef _ANSI_H_
#define _ANSI_H_

#define RESET			"\033[0m"
#define BOLD			"\033[1m"
#define DIM				"\033[2m"
#define UNDERLINE		"\033[4m"
#define INVERSE		"\033[7m"
#define REVERSE		"\033[100m"

#define BLACK			"\033[30m"
#define RED				"\033[31m"
#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define BLUE			"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN			"\033[36m"
#define WHITE			"\033[37m"

#define BrightBlack    "\033[30;1m"
#define BrightRed      "\033[31;1m"
#define BrightGreen    "\033[32;1m"
#define BrightYellow   "\033[33;1m"
#define BrightBlue     "\033[34;1m"
#define BrightMagenta  "\033[35;1m"
#define BrightCyan     "\033[36;1m"
#define BrightWhite    "\033[37;1m"

#define BlackBackground    "\033[40m"
#define RedBackground      "\033[41m"
#define GreenBackground    "\033[42m"
#define YellowBackground   "\033[43m"
#define BlueBackground     "\033[44m"
#define MagentaBackground  "\033[45m"
#define CyanBackground     "\033[46m"
#define WhiteBackground    "\033[47m"

#define ClearScreen    "\033[2J"
#define ClearLine      "\033[2K"

#define StoreCursor    "\033[s"
#define RestoreCursor  "\033[u"

#define HideCursor     "\033[?25l"
#define ShowCursor     "\033[?25h"

#endif
