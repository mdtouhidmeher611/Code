import sys
input=sys.stdin.readline

def solve():
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort(reverse=True)
    from heapq import heappush,heappop
    h=[]
    vis=set()
    for i in range(n):
        heappush(h,(-(a[0]^a[i]),0,i))
        vis.add((0,i))
    s=0
    c=0
    while c<m:
        x,i,j=heappop(h)
        if i!=j:
            s+=-x
            c+=1
        if i+1<n and (i+1,j) not in vis:
            heappush(h,(-(a[i+1]^a[j]),i+1,j))
            vis.add((i+1,j))
        if j+1<n and (i,j+1) not in vis:
            heappush(h,(-(a[i]^a[j+1]),i,j+1))
            vis.add((i,j+1))
    print(s)

solve()
