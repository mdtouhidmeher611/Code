def main():
    import sys
    input = sys.stdin.readline

    n, h = map(int, input().split())
    a = list(map(int, input().split()))
    arr = sorted([(a[i], i) for i in range(n)])

    res = [2]*n
    mn1 = arr[0][0] + arr[1][0] + h
    mx1 = arr[-1][0] + arr[-2][0] + h
    best = mx1 - mn1
    best_res = res[:]

    r2 = [2]*n
    r2[arr[0][1]] = 1
    if n >= 3:
        mn2 = min(arr[0][0] + arr[1][0] + h, arr[1][0] + arr[2][0])
    else:
        mn2 = arr[0][0] + arr[1][0] + h
    mx2 = max(arr[-1][0] + arr[-2][0], arr[0][0] + arr[-1][0] + h)
    g2 = mx2 - mn2

    if g2 < best:
        best = g2
        best_res = r2

    print(best)
    print(*best_res)

if __name__ == "__main__":
    main()
