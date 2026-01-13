n,k=map(int,input().split())
r=list(map(int,input().split()))
used=[False]*n
cnt=0

for i in range(n):
    if used[i]:
        continue
    used[i]=True
    cnt+=1
    rem=k-r[i]
    best=-1
    for j in range(n):
        if not used[j] and r[j]<=rem:
            if best==-1 or r[j]>r[best]:
                best=j
    if best!=-1:
        used[best]=True

print(cnt)
