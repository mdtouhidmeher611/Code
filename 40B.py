s=input().strip()
st=[]
ans=0
cur=0

for c in s:
    if c=="(":
        st.append(cur)
        cur=0
    else:
        if st:
            cur+=1+st.pop()
            ans=max(ans,cur)
        else:
            cur=0
            st.clear()

print(ans*2)
