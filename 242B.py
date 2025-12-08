n=int(input())
seg=[]
for i in range(n):
    l,r=map(int,input().split())
    seg.append((l,r,i+1))

mn=min(s[0] for s in seg)
mx=max(s[1] for s in seg)

for l,r,idx in seg:
    if l==mn and r==mx:
        print(idx)
        break
else:
    print(-1)
