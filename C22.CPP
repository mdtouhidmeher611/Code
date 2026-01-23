#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1005][1005];
bool v[1005][1005];

struct Op {
    int i, j, c;
};

int gc(int r, int c) {
    if (r < 1 || r >= n || c < 1 || c >= m) return -1;
    int k = 0;
    for (int i = r; i <= r + 1; ++i) {
        for (int j = c; j <= c + 1; ++j) {
            if (a[i][j]) {
                if (!k) k = a[i][j];
                else if (k != a[i][j]) return -1;
            }
        }
    }
    return k ? k : -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    queue<pair<int, int>> q;
    vector<Op> res;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (gc(i, j) != -1) {
                q.push({i, j});
                v[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        int k = gc(r, c);
        if (k != -1) {
            res.push_back({r, c, k});
            for (int i = r; i <= r + 1; ++i)
                for (int j = c; j <= c + 1; ++j)
                    a[i][j] = 0;

            for (int i = r - 1; i <= r + 1; ++i) {
                for (int j = c - 1; j <= c + 1; ++j) {
                    if (i >= 1 && i < n && j >= 1 && j < m && !v[i][j]) {
                        if (gc(i, j) != -1) {
                            v[i][j] = 1;
                            q.push({i, j});
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << res.size() << "\n";
    reverse(res.begin(), res.end());
    for (auto &o : res) cout << o.i << " " << o.j << " " << o.c << "\n";

    return 0;
}