n,k=map(int,input().split())
model=[input().strip() for _ in range(n)]
size=n**k
res=[[""]*size for _ in range(size)]

for i in range(size):
    for j in range(size):
        x=i
        y=j
        c="."
        for _ in range(k):
            if model[x% n][y% n]=="*":
                c="*"
                break
            x//=n
            y//=n
        res[i][j]=c

for row in res:
    print("".join(row))
