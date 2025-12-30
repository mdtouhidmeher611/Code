r=input().strip()
k=input().strip()

rx=ord(r[0])-ord('a')
ry=int(r[1])-1
kx=ord(k[0])-ord('a')
ky=int(k[1])-1

dirs=[(2,1),(2,-1),(-2,1),(-2,-1),(1,2),(1,-2),(-1,2),(-1,-2)]

def inb(x,y):
    return 0<=x<8 and 0<=y<8

res=0
for i in range(8):
    for j in range(8):
        if (i==rx and j==ry) or (i==kx and j==ky):
            continue
        # knight at (i,j) must not attack rook/knight
        bad=False
        for dx,dy in dirs:
            if (i+dx==rx and j+dy==ry) or (i+dx==kx and j+dy==ky):
                bad=True
                break
        if bad:
            continue
        # rook attacks (i,j)?
        if i==rx or j==ry:
            continue
        res+=1

print(res)
