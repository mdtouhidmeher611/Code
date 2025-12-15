n=int(input())
s=input().strip()

res=[]
i=0
while i<n:
    if n-i==4:
        res.append(s[i:i+2])
        i+=2
    else:
        res.append(s[i:i+3])
        i+=3

print('-'.join(res))
