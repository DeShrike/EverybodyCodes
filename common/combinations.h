#ifndef _COMBINATIONS_H_
#define _COMBINATIONS_H_

#include <stdbool.h>
#include <stddef.h>

//  C(n,k) = n! / (k! * (n-k)!)

typedef bool(*combinations_callback)(int items[], size_t size, void* ctx);

bool combinations(int arr[], size_t x, size_t y, combinations_callback callback, void* ctx);

#endif
