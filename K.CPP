#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)  {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    auto ok = [&](ll x) {
        vector<ll> a(n, 0);
        for (int i = n - 1; i >= 2; i--) {
            if (h[i] + a[i] < x) return false;
            ll d = min(h[i], h[i] + a[i] - x) / 3;
            a[i - 1] += d;
            a[i - 2] += 2 * d;
        }
        return h[0] + a[0] >= x && h[1] + a[1] >= x;
    };

    ll l = 1, r = 1e9, ans = 1;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (ok(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << "\n";
}

    return 0;
}