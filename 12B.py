a=input().strip()
b=input().strip()

a_sorted=''.join(sorted(a))
a_sorted=a_sorted.lstrip('0')
if a_sorted=='':
    a_sorted='0'

if a_sorted==b:
    print("OK")
else:
    print("WRONG_ANSWER")
