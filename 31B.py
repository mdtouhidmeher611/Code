s=input().strip()
n=len(s)
if n<3 or s[0]=='@' or s[-1]=='@':
    print("No solution")
    exit()

ats=[i for i,c in enumerate(s) if c=='@']
if len(ats)==0:
    print("No solution")
    exit()

res=[]
prev=0
for i in range(len(ats)-1):
    x=ats[i]
    y=ats[i+1]
    if y-x<=2:
        print("No solution")
        exit()
    res.append(s[prev:y-1+1])
    prev=y-1+1
res.append(s[prev:])
print(",".join(res))
