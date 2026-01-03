n=int(input())
maxx=0
for _ in range(n):
    x,y=map(int,input().split())
    d=x*x+y*y
    if d>maxx:
        maxx=d
print(maxx**0.5)
