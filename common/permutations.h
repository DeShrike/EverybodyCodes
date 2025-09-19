#ifndef _PERMUTATIONS_H_
#define _PERMUTATIONS_H_

#include <stdbool.h>
#include <stddef.h>

typedef bool(*permutation_callback)(int items[], size_t size, void* ctx);

bool permutations(int* array, size_t n, size_t k, permutation_callback process, void* ctx);

#endif
