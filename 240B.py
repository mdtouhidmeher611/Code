def solve():
    a,b,w=map(int,input().split())
    w*=1000
    mn=w//b
    mx=w//a
    if mn>mx:
        print("UNSATISFIABLE")
    else:
        print(mn,mx)

solve()
