n=int(input())
pts=[]
from collections import Counter

cx=Counter()
cy=Counter()

for _ in range(n):
    x,y=map(int,input().split())
    pts.append((x,y))
    cx[x]+=1
    cy[y]+=1

ans=0
for x,y in pts:
    ans+=(cx[x]-1)*(cy[y]-1)

print(ans)
