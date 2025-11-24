n, d, l = map(int, input().split())

odd_count = (n + 1) // 2
even_count = n // 2

min_odd = odd_count
max_odd = odd_count * l
min_even = even_count
max_even = even_count * l

if d < min_odd - max_even or d > max_odd - min_even:
    print(-1)
else:
    odd_sum = 0
    even_sum = 0
    
    found = False
    for o in range(min_odd, max_odd + 1):
        e = o - d
        if min_even <= e <= max_even:
            odd_sum = o
            even_sum = e
            found = True
            break
    
    if not found:
        print(-1)
    else:
        result = []
        
        base_odd = odd_sum // odd_count
        rem_odd = odd_sum % odd_count
        for i in range(odd_count):
            if i < rem_odd:
                result.append(base_odd + 1)
            else:
                result.append(base_odd)
        
        if even_count > 0:
            base_even = even_sum // even_count
            rem_even = even_sum % even_count
            for i in range(even_count):
                if i < rem_even:
                    result.insert(2 * i + 1, base_even + 1)
                else:
                    result.insert(2 * i + 1, base_even)
        
        print(' '.join(map(str, result)))