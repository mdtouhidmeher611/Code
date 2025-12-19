n,v=map(int,input().split())
ok=True
for _ in range(n):
    x,t=map(int,input().split())
    if x>v*t:
        ok=False
        break
print("YES" if ok else "NO")
