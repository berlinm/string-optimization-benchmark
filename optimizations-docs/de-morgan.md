# Example 2 - Context aware optimizations (dangerous game)

## Code 

### Unoptimized code
``` python
def verify_user(sessions, request):
	for session in sessions.items():
		if session.user == request.user and session.key == request.key:
			return True # Access granted
		else:
			return False # Access denied
```

### Optimized Code
```python
def verify_user(sessions, request):
	return request.user in [session.user for session in sessions] and request.key in [session.key for session in keys]
```

## Explanation

### What is the optimization?
Dont know

### Bug:
If the user exists but it is not the correct key, yet a different user has this type of key, it is not logically correct to optimize like this.

One thought: I dont think this optimizes something at all.