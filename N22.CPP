#include <bits/stdc++.h>

using namespace std;

long long f[2005][2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    sort(s.begin(), s.end());

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            f[i][j] = (s[j] - s[i]) + min(f[i + 1][j], f[i][j - 1]);
        }
    }

    cout << f[0][n - 1] << endl;
    return 0;
}