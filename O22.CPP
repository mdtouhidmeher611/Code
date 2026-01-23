#include <bits/stdc++.h>

using namespace std;

const int M = 500005;
int p[M], t[M], x[M], y[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> x[i];
        if (t[i] == 2) cin >> y[i];
    }
    for (int i = 0; i < M; ++i) 
        p[i] = i;

    vector<int> res;
    for (int i = q - 1; i >= 0; --i) {
        if (t[i] == 1) 
            res.push_back(p[x[i]]);
        else 
            p[x[i]] = p[y[i]];
    }

    reverse(res.begin(), res.end());

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    return 0;
}