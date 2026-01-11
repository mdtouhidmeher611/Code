s=input()
cur=""
ans=0
for c in s:
    if c.isdigit():
        cur+=c
    else:
        if cur:
            ans+=int(cur)
            cur=""
if cur:
    ans+=int(cur)
print(ans)
