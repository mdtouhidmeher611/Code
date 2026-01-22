#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void calculate() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n), d(n);
    for (int i = 0; i < n; i++) 
        cin >> x[i];
    for (int i = 0; i < n; i++) 
        cin >> y[i];
    for (int i = 0; i < n; i++) 
        d[i] = y[i] - x[i];

    sort(d.begin(), d.end());

    int ans = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (d[l] + d[r] >= 0) {
            ans++;
            l++;
            r--;
        } 
        else {
            l++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        calculate();
    }
    return 0;
}