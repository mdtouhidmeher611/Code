MOD = 10**9 + 7

def solve():
    import sys
    n, m, k = map(int, sys.stdin.read().split())
    if m < n:
        print(0)
        return
    cnt = m - n + 1
    mx = n*n
    fact = [1]*(mx+1)
    for i in range(1, mx+1):
        fact[i] = fact[i-1]*i % MOD
    invfact = [1]*(mx+1)
    invfact[mx] = pow(fact[mx], MOD-2, MOD)
    for i in range(mx, 0, -1):
        invfact[i-1] = invfact[i]*i % MOD
    def C(a, b):
        if b<0 or b>a:
            return 0
        return fact[a]*invfact[b]%MOD*invfact[a-b]%MOD
    print(cnt * C(mx, k) % MOD)

solve()
