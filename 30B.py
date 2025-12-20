n,m=map(int,input().split())
a=list(map(int,input().split()))
s=set(a)
if len(s)==m:
    print("YES")
else:
    print("NO")
