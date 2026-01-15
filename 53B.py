n=int(input())
a=list(map(int,input().split()))

ans=0
i=0
while i<n:
    j=i
    while j<n and a[j]==a[i]:
        j+=1
    ans+=j-i
    i=j

print(ans)
