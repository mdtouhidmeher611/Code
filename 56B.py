n=int(input())
p=list(map(int,input().split()))

l=0
while l+1<n and p[l]<p[l+1]:
    l+=1

r=n-1
while r-1>=0 and p[r]>p[r-1]:
    r-=1

if l>=r:
    print(0,0)
else:
    mn=min(p[l:r+1])
    mx=max(p[l:r+1])

while l-1>=0 and p[l-1]>mn:
    l-=1
while r+1<n and p[r+1]<mx:
    r+=1

print(l+1,r+1)
