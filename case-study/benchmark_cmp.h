#include <string.h>
int strcmp_not_optimized(const char* s1, const char* s2);
int strcmp_optimized_without_bug(const char* s1, const char* s2);
int strcmp_optimized_with_bug(const char* s1, const char* s2);