n=int(input())
a=list(map(int,input().split()))
mn=10**18
x=y=0
for i in range(n):
    d=abs(a[i]-a[(i+1)%n])
    if d<mn:
        mn=d
        x=i+1
        y=(i+1)%n+1
print(x,y)
