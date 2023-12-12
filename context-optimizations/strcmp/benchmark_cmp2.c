#include "benchmark_cmp.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*
This is an optimized version of strcmp, which works for Israeli ID comparation.
Requires:   strlen(s1) == strlen(s2) == 9
Ensures:    strcmp_not_optimized_without_bug(s1, s2) iff strcmp(s1,s2) == 0
*/
int strcmp_not_optimized(const char* s1, const char* s2)
{
    int i = 0;
    while (i <= 8 && *(s1 + i) == *(s2 + i))
        i++;

    // printf("DEBUG:  %s(%s, %s): i = %d\n", "not-optimized", s1, s2, i);
    int return_value = i > 8 ? 0 : *(const unsigned char*)s1 - *(const unsigned char*)s2;
    // printf("DEBUG:  %d\n", return_value);
    return return_value;
}

/*
This is an optimized version of strcmp, which works for Israeli ID comparation.
Optimization: Because the last digit is more evenly distributed, comparing from the end will reduce the runtime.
Requires:   strlen(s1) == strlen(s2) == 9
Ensures:    strcmp_optimized_without_bug(s1, s2) iff strcmp(s1,s2) == 0
*/
int strcmp_optimized_without_bug(const char* s1, const char* s2)
{
    int i = 8;
    while (i >= 0 && *(s1 + i) == *(s2 + i))
    {
        i--;
    }
    // printf("DEBUG:  %s(%s, %s): i = %d\n", "correctly-optimized", s1, s2, i);
    int return_value = i < 0 ? 0 : *(const unsigned char*)s1 - *(const unsigned char*)s2;
    // printf("DEBUG:  %d\n", return_value);
    return return_value;
}


// Failing on test-case:
int strcmp_optimized_with_bug(const char* s1, const char* s2)
{
    int i = 8;
    while (*(s1 + i) == *(s2 + i)){
        i--;
        if (i == 1){
            return 0;
        }
    }
    // printf("DEBUG:  %s(%s, %s): i = %d\n", "incorrectly-optimized", s1, s2, i);
    int return_value = i < 0 ? 0 : *(const unsigned char*)s1 - *(const unsigned char*)s2;
    // printf("DEBUG:  %d\n", return_value);
    return return_value;
}