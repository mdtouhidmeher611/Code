#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve_case() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll sum = 0;
    ll mx = a[0];
    for (ll x : a) {
        sum += x;
        mx = max(mx, x);
    }
    cout << sum << " " << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve_case();
}
