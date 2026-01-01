n=int(input())
a=list(map(int,input().split()))

ans=0
mx=a[0]
for i in range(1,n):
    if a[i]<mx:
        ans+=mx-a[i]
    else:
        mx=a[i]

print(ans)
