cnt={c:0 for c in "ABC"}

for _ in range(3):
    s=input().strip()
    if s[1]=='>':
        cnt[s[0]]+=1
    else:
        cnt[s[2]]+=1

res=sorted(cnt,key=lambda x:cnt[x])

if cnt[res[0]]==cnt[res[1]] or cnt[res[1]]==cnt[res[2]]:
    print("Impossible")
else:
    print("".join(res))
