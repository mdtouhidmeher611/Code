n=int(input())
a=list(map(int,input().split()))

a.sort()
i=0
ans=0
while i<n:
    j=i
    while j<n and a[j]==a[i]:
        j+=1
    if j-i>=2:
        ans+=1
    i=j

print(ans)
