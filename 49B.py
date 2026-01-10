W,H,w,h=map(int,input().split())
print(max((W//w)*(H//h),(W//h)*(H//w)))
