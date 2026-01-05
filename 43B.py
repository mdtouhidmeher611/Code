from collections import Counter

a=input()
b=input()

ca=Counter(a)
cb=Counter(b)

for k,v in cb.items():
    if ca[k]<v:
        print("NO")
        break
else:
    print("YES")
