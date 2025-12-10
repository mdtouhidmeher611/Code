n=int(input())
n=abs(n)
s=0
k=0
while True:
    k+=1
    s+=k
    if s>=n and (s-n)%2==0:
        print(k)
        break
