#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) : p(n + 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) p[b] = a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    DSU dsu(n);

    unordered_map<int, int> last;

    for (int x = 1; x <= n; x++) {
        int v = x;
        for (int i = 2; i * i <= v; i++) {
            if (v % i == 0) {
                if (last.count(i))
                    dsu.unite(x, last[i]);
                last[i] = x;
                while (v % i == 0) v /= i;
            }
        }
        if (v > 1) {
            if (last.count(v))
                dsu.unite(x, last[v]);
            last[v] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) != dsu.find(p[i])) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
