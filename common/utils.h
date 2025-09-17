#ifndef _UTILS_H_
#define _UTILS_H_

#define false 0
#define true  1

typedef unsigned char bool;
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;

/*
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
*/

float map(float value, float minin, float maxin, float minout, float maxout);
float clamp(float value, float minimum, float maximum);
bool ends_with(const char* str, const char* substr);
char *args_shift(int *argc, char ***argv);
void print_memory(void);
int gcd(int a, int b);
void print_roman_year(int year);
void wait_for_key(void);

/*
#include <time.h>

clock_t start_time, end_time;
start_time = clock();

end_time = clock();

printf("Time Taken: %f", (end_time - start_time) / CLK_TCK);
*/


#endif
