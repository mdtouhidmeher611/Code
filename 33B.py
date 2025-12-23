import sys

INF = 10**9

s = list(input().strip())
t = list(input().strip())

if len(s) != len(t):
    print(-1)
    sys.exit(0)

n = int(input())

cost = [[INF] * 26 for _ in range(26)]

for i in range(26):
    cost[i][i] = 0

for _ in range(n):
    a, b, c = input().split()
    a = ord(a) - ord('a')
    b = ord(b) - ord('a')
    c = int(c)
    cost[a][b] = min(cost[a][b], c)

for k in range(26):
    for i in range(26):
        for j in range(26):
            if cost[i][j] > cost[i][k] + cost[k][j]:
                cost[i][j] = cost[i][k] + cost[k][j]

result = []
total = 0

for i in range(len(s)):
    x = ord(s[i]) - ord('a')
    y = ord(t[i]) - ord('a')
    
    best = INF
    best_char = -1
    
    for z in range(26):
        if cost[x][z] + cost[y][z] < best:
            best = cost[x][z] + cost[y][z]
            best_char = z
    
    if best == INF:
        print(-1)
        sys.exit(0)
    
    total += best
    result.append(chr(best_char + ord('a')))

print(total)
print(''.join(result))