#include "benchmark_cmp.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LINES 10000002
#define ID_LENGTH 9
#define SHOULD_FAIL 1
#define SHOULD_SUCCEED 0

int lineCount;

char a1[MAX_LINES][ID_LENGTH + 1]; // +1 for null terminator
char a2[MAX_LINES][ID_LENGTH + 1];

int parse_test_file(){
	FILE *file = fopen("test_cases.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    lineCount = 0;

    while (lineCount < MAX_LINES && fscanf(file, "%9s %9s", a1[lineCount], a2[lineCount]) == 2) {
        lineCount++;
    }

    fclose(file);

    // Now, a1 and a2 arrays contain pairs of words from each line
    // with a1[i] and a2[i] corresponding to the words from the i'th line.

    // for (int i = 0; i < lineCount; i++) {
    //     printf("Pair %d: %s %s\n", i + 1, a1[i], a2[i]);
    // }

    return 0;
}

int test_single_correctness(int (*original_strcmp)(const char*, const char*),int (*optimized_strcmp)(const char*, const char*), char* s1, char* s2, int should_fail){
    int original_result = original_strcmp(s1, s2);
    int optimized_result = optimized_strcmp(s1, s2);
    if ((!original_result || !optimized_result) && original_result != optimized_result){
        if (!should_fail)
            printf("ERROR:  different results for optimized (%d) and original (%d). For input %s %s\n", optimized_result, original_result, s1, s2);
        return -1;
    }
    return 0;
}

int test_correctness(int (*original_strcmp)(const char*, const char*),int (*optimized_strcmp)(const char*, const char*), int should_fail){
    int error = 0;
    for (int i = 0; i < lineCount; i++){
        error = error || test_single_correctness(original_strcmp, optimized_strcmp, a1[i], a2[i], should_fail);
    }
    if (!error){
        if (!should_fail) 
            printf("SUCCESS: Correctness check passed.\n");
        return 0;
    }
    return -1;
}

int test_efficiency(int (*original_strcmp)(const char*, const char*),int (*optimized_strcmp)(const char*, const char*)){
    clock_t start_time, end_time;
    double original_strcmp_time, optimized_strcmp_time;
    start_time = clock();

    for (int i = 0; i < lineCount; i++){
        char* s1 = a1[i];
        char* s2 = a2[i];
        int original_result = original_strcmp(s1, s2);
    }
    end_time = clock();
    original_strcmp_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    start_time = clock();

    for (int i = 0; i < lineCount; i++){
        char* s1 = a1[i];
        char* s2 = a2[i];
        int optimized_results = optimized_strcmp(s1, s2);
    }
    end_time = clock();
    optimized_strcmp_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("RESULTS:\n");
    printf("Optimized strcmp took %f seconds\n", optimized_strcmp_time);
    printf("Not-optimized strcmp took %f seconds\n", original_strcmp_time);

}

int main(int argc, char** argv){
    // if (argc < 3){
    //     return 0;
    // }

    // char* s1 = argv[1];
    // char* s2 = argv[2];

	parse_test_file();

    // Single
    // // Control check
    // if (test_single_correctness(strcmp_not_optimized, strcmp_optimized_without_bug, s1, s2) != 0){
    //     printf("ERROR:  Control failed.");
    // }
    // // Actual check
    // if (test_single_correctness(strcmp_not_optimized, strcmp_optimized_with_bug, s1, s2) != 0){
    //     printf("ERROR: Test Failed.");
    // }

    // Enhancive
    // Control check
    if (test_correctness(strcmp_not_optimized, strcmp_optimized_without_bug, SHOULD_SUCCEED) != 0){
        printf("ERROR:  Control failed\n");
    }
    // Actual check
    if (test_correctness(strcmp_not_optimized, strcmp_optimized_with_bug, SHOULD_FAIL) != 0){
        printf("SUCCESS: Incorrect optimization test Failed (As it should)\n");
    }

    printf("Testing not optimized vs. optimized correctly:\n");
    test_efficiency(strcmp_not_optimized, strcmp_optimized_without_bug);

    printf("Testing not optimized vs. optimized incorrectly:\n");
    test_efficiency(strcmp_not_optimized, strcmp_optimized_with_bug);
}