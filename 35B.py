n,m,k=map(int,input().split())
arr=[[""]*m for _ in range(n)]
pos={}
for _ in range(k):
    q=input().split()
    if q[0]=="+1":
        x=int(q[1])-1
        y=int(q[2])-1
        id=q[3]
        i,j=x,y
        placed=False
        while i<n:
            if arr[i][j]=="":
                arr[i][j]=id
                pos[id]=(i+1,j+1)
                placed=True
                break
            j+=1
            if j==m:
                i+=1
                j=0
        if not placed:
            pass
    else:
        id=q[1]
        if id in pos:
            p=pos[id]
            print(p[0],p[1])
            arr[p[0]-1][p[1]-1]=""
            del pos[id]
        else:
            print(-1,-1)
