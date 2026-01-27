n, d = map(int, input().split())
a = list(map(int, input().split()))
moves = 0
for i in range(1, n):
    if a[i] <= a[i-1]:
        diff = a[i-1] - a[i] + 1
        k = (diff + d - 1) // d
        a[i] += k * d
        moves += k
print(moves)
