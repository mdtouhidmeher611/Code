n,x=map(int,input().split())
L=-10**18
R=10**18

for _ in range(n):
    a,b=map(int,input().split())
    if b<x:
        continue
    L=max(L,a)
    R=min(R,b)

if L<=R:
    print(max(L,x))
else:
    print(-1)
