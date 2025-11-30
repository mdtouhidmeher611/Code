a, b, c = map(int, input().split())
mx = a * b * c
divs = [0] * (mx + 1)

for i in range(1, mx + 1):
    for j in range(i, mx + 1, i):
        divs[j] += 1

ans = 0
for i in range(1, a + 1):
    for j in range(1, b + 1):
        for k in range(1, c + 1):
            ans += divs[i * j * k]

print(ans)
