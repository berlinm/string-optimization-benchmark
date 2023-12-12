# Example 1 - Arithmetic Optimizations

## Exmaple 2.1 - Arithmetic optimizations - Addition

#### Unoptimized code
``` python
def times_three(x):
	return 3*x
```

#### Optimized Code
```python
def times_three(x):
	return x + x + x
```

#### What is the optimization?
Previous work have shown that addition is in general faster than multiplication. Therefore, adding x+x+x is faster than calculating 3 times x.


#### Bug:
1. What if reading x has side affects?
2. What if x changes in-between the reads?


## Exmaple 2.2 - Rounding optimization
#### Unoptimized code
``` python
Not baked idea:
These are not equal:
10*e-6 + 10*e6 + -10*e6 == 0
10*e-6 + (10*e6 + (-10*e6)) == 10*e-6
```

#### Optimized Code
```python
```

#### What is the optimization?
Here goes an explanation about the optimization


#### Bug:
Here goes an explanation about the bug that is rooted in the optimization.


