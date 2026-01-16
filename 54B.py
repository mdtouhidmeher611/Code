n,m=map(int,input().split())
a=[list(map(int,input().split())) for _ in range(n)]

mn=min(min(r) for r in a)
mx=max(max(r) for r in a)

cnt=0
for i in range(n):
    for j in range(m):
        if a[i][j]==mn or a[i][j]==mx:
            cnt+=1

print(cnt)
