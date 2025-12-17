n=int(input())
a=[list(map(int,input().split())) for _ in range(n)]
win=[0]*n
for i in range(n):
    for j in range(n):
        if a[i][j]==1:
            win[i]+=1

for i in range(n):
    ok=True
    for j in range(n):
        if i!=j and a[i][j]==a[j][i]:
            ok=False
            break
    if ok:
        print(i+1)
        break
