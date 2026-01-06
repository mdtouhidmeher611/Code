n,a,b,c=map(int,input().split())
cnt=0
for x in range(a+1):
    for y in range(b+1):
        rem = n - (x*0.5 + y*1)
        if rem < 0:
            break
        if rem*2 <= c*4 and rem*2 == int(rem*2):
            z = int(rem*2//4)
            if z <= c:
                cnt += 1
print(cnt)
