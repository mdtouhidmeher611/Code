def run_prog(s):
    res = [0]*10
    cp = 0
    dp = 1  # 1 = right, -1 = left
    while 0 <= cp < len(s):
        c = s[cp]
        if c.isdigit():
            d = ord(c) - ord('0')
            res[d] += 1
            d -= 1
            if d < 0:
                s = s[:cp] + s[cp+1:]
                if dp == -1:
                    cp -= 1
            else:
                s = s[:cp] + chr(ord('0')+d) + s[cp+1:]
                cp += dp
        else:
            dp = 1 if c == '>' else -1
            cp += dp
            if 0 <= cp < len(s) and (s[cp] == '<' or s[cp] == '>'):
                s = s[:cp-dp] + s[cp-dp+1:]
                if dp == -1:
                    cp -= 1
    return res

def main():
    import sys
    input = sys.stdin.readline
    n, q = map(int, input().split())
    s0 = input().strip()
    for _ in range(q):
        l, r = map(int, input().split())
        sub = s0[l-1:r]
        ans = run_prog(sub)
        print(" ".join(str(ans[i]) for i in range(10)))

if __name__ == "__main__":
    main()
