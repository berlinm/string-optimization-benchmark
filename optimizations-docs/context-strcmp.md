# Example 2 - Context-Aware Optimizations (dangerous game)

## Exmaple 2.1 - Context-Aware Optimizations - strcmp

### Example 2.1.1 - Context-Aware Optimizations - strcmp - From the end

#### Unoptimized code
``` c
int strcmp_not_optimized(const char* s1, const char* s2)
{
    int i = 0;
    while (i <= 8 && *(s1 + i) == *(s2 + i))
        i++;

    int return_value = i > 8 ? 0 : *(const unsigned char*)s1 - *(const unsigned char*)s2;
    return return_value;
}
```

#### Optimized Code
```c
int strcmp_optimized_with_bug(const char* s1, const char* s2)
{
    int i = 8;
    while (*(s1 + i) == *(s2 + i)){
        i--;
    }
    int return_value = i < 0 ? 0 : *(const unsigned char*)s1 - *(const unsigned char*)s2;
    return return_value;
}
```

#### What is the optimization?
Optimization: Because the last digit is more evenly distributed, comparing from the end will reduce the runtime.


#### Bug:
1. Obviously, context-based optimization can cause out-of-context bugs.
2. ?

### Example 2.1.2 - Context-Aware Optimizations - strcmp - hamming-distance

#### Unoptimized code
``` c
int strcmp_not_optimized(const char* s1, const char* s2)
{
    while(*(s1) && (*s1 == *s2))
    {
        s1++; s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
```

#### Optimized Code
```c
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
    return *(const unsigned char*)(s1) - *(const unsigned char*)(s2);
}
```

#### What is the optimization?
Optimization: Because israeli ID numbers are generated with luhan algorithm, there cannot be 2 different IDs that differs by only one digit.


#### Bug:
1. Obviously, context-based optimization can cause out-of-context bugs.
2. ?
