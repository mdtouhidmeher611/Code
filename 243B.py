import sys
input = sys.stdin.readline

n, m, h, t = map(int, input().split())
g = [[] for _ in range(n+1)]
edges = []

for _ in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
    edges.append((u, v))

deg = [len(g[i]) for i in range(n+1)]

def try_edge(u, v):
    if deg[u] - 1 < h or deg[v] - 1 < t:
        return False

    su = set(g[u])
    sv = set(g[v])

    common = (su & sv)
    su_only = [x for x in g[u] if x != v and x not in sv]
    sv_only = [x for x in g[v] if x != u and x not in su]

    need_u = h
    need_v = t

    u_ans = []
    v_ans = []

    for x in su_only:
        if need_u == 0: break
        u_ans.append(x)
        need_u -= 1

    for x in sv_only:
        if need_v == 0: break
        v_ans.append(x)
        need_v -= 1

    common = list(common - {u, v})

    i = 0
    while need_u > 0 and i < len(common):
        u_ans.append(common[i])
        i += 1
        need_u -= 1

    while need_v > 0 and i < len(common):
        v_ans.append(common[i])
        i += 1
        need_v -= 1

    if need_u == 0 and need_v == 0:
        print("YES")
        print(u, v)
        print(*u_ans)
        print(*v_ans)
        return True

    return False


for u, v in edges:
    if try_edge(u, v): 
        sys.exit(0)
    if try_edge(v, u):
        sys.exit(0)

print("NO")
