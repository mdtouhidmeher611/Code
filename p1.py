import sys
import math

input = sys.stdin.read
data = input().split()

index = 0
t = int(data[index])
index += 1

results = []

for _ in range(t):
    n = int(data[index])
    index += 1
    a = list(map(int, data[index:index+n]))
    index += n
    index += n  # skip b since all bi = 1

    found = False
    for i in range(n):
        for j in range(i+1, n):
            if math.gcd(a[i], a[j]) > 1:
                results.append(0)
                found = True
                break
        if found:
            break

    if not found:
        min_cost = float('inf')
        for i in range(n):
            for j in range(i+1, n):
                for x in range(5):  # try incrementing a[i] by x
                    for y in range(5):  # and a[j] by y
                        if math.gcd(a[i]+x, a[j]+y) > 1:
                            min_cost = min(min_cost, x + y)
        results.append(min_cost)

print("\n".join(map(str, results)))