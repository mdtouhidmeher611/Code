s = input().strip()
try:
    n = int(s)
    s = input().strip()
except:
    pass

i = 0
ans = 0
L = len(s)
while i < L:
    if s[i] == 'O':
        j = i
        while j < L and s[j] == 'O':
            j += 1
        x = j - i
        ans += x * x
        i = j
    else:
        i += 1
print(ans)
