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
    while(*(s1) && (*s1 == *s2))
    {
        s1++; s2++;
    }
    // printf("DEBUG:   %s(%s, %s): i = %d\n", "not-optimized", s1, s2, *(const unsigned char*)s1 - *(const unsigned char*)s2);
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

/*
This is an optimized version of strcmp, which works for Israeli ID comparation.
Optimization: Because israeli ID numbers are generated with luhan algorithm, there cannot be 2 different IDs that differs by only one digit.
Requires:   strlen(s1) == strlen(s2) == 9, both s1 and s2 are israeli valid ID numbers.
Ensures:    strcmp_optimized_without_bug(s1, s2) iff strcmp(s1,s2) == 0
*/
int strcmp_optimized_without_bug(const char* s1, const char* s2)
{
    while(*s1 == *s2)
    {
        s1++; s2++;
        if (*(s1 + 1) == 0){
            // Equal
            return 0;
        }
    }
    // printf("DEBUG:   %s(%s, %s): i = %d\n", "correctly-optimized", s1, s2, *(const unsigned char*)s1 - *(const unsigned char*)s2);
    return *(const unsigned char*)(s1) - *(const unsigned char*)(s2);
}

// Failing on test-case:
int strcmp_optimized_with_bug(const char* s1, const char* s2)
{
    while((*s1 == *s2))
    {
        s1++; s2++;
        if (*(s1 + 2) == 0){
            // Equal
            return 0;
        }
    }
    // printf("DEBUG:   %s(%s, %s): i = %d\n", "incorrectly-optimized", s1, s2, *(const unsigned char*)s1 - *(const unsigned char*)s2);
    return *(const unsigned char*)(s1) - *(const unsigned char*)(s2);
}