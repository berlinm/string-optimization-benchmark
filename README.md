# String Optimization Benchmark

In this project, we focus on implementing domain-specific optimizations for relatively simple C library functions, such as `strcmp`, using domain knowledge. Additionally, we explore optimizations that introduce bugs, which are included in the template for each case study.

For each case study, we provide three functions:

1. **not-optimized**: The original, unoptimized function.
2. **optimized-correctly**: The optimized function that maintains the correct behavior.
3. **optimized-incorrectly**: The optimized function that intentionally introduces a bug.

## Benchmarks

Currently, we have implemented two types of tests: **Correctness** and **Performance**.

### Performance

The performance test compares the efficiency of the examined functions when processing a large number of inputs.

### Correctness

The correctness test verifies the functions' adherence to their intended behavior. Specifically, for our primary focus:

1. The **not-optimized** function and the **optimized-correctly** function must maintain their contractual behavior.
2. The **optimized-incorrectly** function should intentionally fail to uphold its contractual behavior.

This project aims to explore how optimization impacts the correctness and performance of these library functions. Feel free to explore the code and results to gain insights into optimization strategies and potential pitfalls.
