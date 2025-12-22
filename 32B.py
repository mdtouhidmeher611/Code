s = input().strip()

i = 0
res = []
n = len(s)

while i < n:
    if s[i] == '.':
        res.append('0')
        i += 1
    else:
        if s[i + 1] == '.':
            res.append('1')
        else:
            res.append('2')
        i += 2

print(''.join(res))