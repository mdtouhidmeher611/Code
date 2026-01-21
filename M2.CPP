#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    long long m = 998244353;
    vector<long long> p(q + 1);
    p[0] = 1;
    for (int i = 1; i <= q; i++) p[i] = (p[i - 1] * 10) % m;

    deque<int> s;
    s.push_back(1);
    long long v = 1;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            s.push_back(x);
            v = (v * 10 + x) % m;
        } else if (t == 2) {
            int d = s.front();
            s.pop_front();
            v = (v - d * p[s.size()] % m + m) % m;
        } else {
            cout << v << "\n";
        }
    }

    return 0;
}