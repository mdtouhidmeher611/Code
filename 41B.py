s1=input().strip()
s2=input().strip()
s3=input().strip()

from collections import Counter

c1=Counter(s1)
c2=Counter(s2)
c3=Counter(s3)

for k,v in c1.items():
    if c2[k]+c3[k]!=v:
        print("NO")
        break
else:
    print("YES")
