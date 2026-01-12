n=int(input())
s=input().strip()

from collections import Counter

cnt=Counter(s)
ans=0
for v in cnt.values():
    ans+=v*(v-1)//2

print(ans)
