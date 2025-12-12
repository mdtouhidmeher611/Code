s=input().strip()
ans=[]
for c in s:
    if 'A'<=c<='Z':
        ans.append(chr((ord(c)-ord('A')+13)%26+ord('A')))
    elif 'a'<=c<='z':
        ans.append(chr((ord(c)-ord('a')+13)%26+ord('a')))
    else:
        ans.append(c)
print(''.join(ans))
