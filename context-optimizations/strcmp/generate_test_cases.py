from json import load
from random import choice

with open('ids.json', 'r') as f:
    ids = load(f)

test_cases = []
for _ in range(10000000):
    id1, id2 = choice(ids), choice(ids) # + (choice(ids) if choice(range(1,4)) == 3 else "")
    test_cases.append(f"{id1} {id2}")

test_cases = "\n".join(test_cases)
with open('test_cases.txt', 'w') as f:
    f.write(test_cases)