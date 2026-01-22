#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void calculate() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<long long> f(n + 1);
    long long r = 0;

    for (int i = n; i >= 1; i--) {
        if (i + a[i] > n) f[i] = a[i];
        else f[i] = a[i] + f[i + a[i]];
        r = max(r, f[i]);
    }

    cout << r << endl;
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