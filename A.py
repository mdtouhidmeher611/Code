t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = input().strip()

    cnt = [0] * 7
    for c in a:
        cnt[ord(c) - ord('A')] += 1

    need = 0
    for i in range(7):
        need += max(0, m - cnt[i])

    print(need)
