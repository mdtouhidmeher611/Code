def s(x):
    r=0
    while x>0:
        r+=x%10
        x//=10
    return r

import math
n=int(input())
root=int(math.isqrt(n))
ans=-1
for x in range(max(1,root-200),root+201):
    if x*x>n: break
    if x*x+s(x)*x==n:
        ans=x
        break
print(ans)
