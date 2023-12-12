# strcmp

We implement several strcmp optimization attempts, as described in main project README.md

1. **bencmark_cmp1** - Because israeli ID numbers are generated with luhan algorithm, there cannot be 2 different IDs that differs by only one digit. Thus, given that the two inputs are valid ID numbers, it is enough to check 8 digit out of 9.
2. **benchmark_cmp2** - Because the last digit is more evenly distributed, comparing from the end will reduce the runtime.