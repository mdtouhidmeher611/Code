n,k=map(int,input().split())
a=list(map(int,input().split()))
win=[True]*n

for j in range(1,k+1):
    x=a[j-1]
    win[x-1]=False

ans=[]
for i in range(n):
    if win[i]:
        ans.append(i+1)

if ans:
    print(*ans)
else:
    print(-1)
