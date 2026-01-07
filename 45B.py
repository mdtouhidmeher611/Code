import sys
input=sys.stdin.readline

n,m=map(int,input().split())
g=[0]+list(map(int,input().split()))
v=list(map(int,input().split()))
b=list(map(int,input().split()))

res=[0]*m
first=[-1]*(n+1)

for i in range(m):
    ai=(v[i]+(res[i-1] if i>0 else 0))%n
    if ai==0: ai=n
    rating=b[i]
    cur=ai
    steps=0
    while rating>0:
        if first[cur]==-1:
            first[cur]=i
            res[i]+=1
        nxt=g[cur]
        cur=nxt
        rating-=1
        steps+=1
        if steps>n: break

for x in res:
    print(x)
