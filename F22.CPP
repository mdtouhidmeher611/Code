#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int mx(int a, int b, int c) {
    for (int i = 0; i <= 3; i++) {
        if (a != i && b != i && c != i) 
            return i;
    }
    return 3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;

    vector<vector<long long>> pre(n + 1, vector<long long>(3, 0));
    vector<vector<long long>> suf(n + 1, vector<long long>(3, 0));

    for (int i = 0; i < n; i++) {
        for (int v = 0; v < 3; v++) pre[i + 1][v] = pre[i][v];
        if (s[i] == 'M') pre[i + 1][a[i]]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int v = 0; v < 3; v++) suf[i][v] = suf[i + 1][v];
        if (s[i] == 'X') suf[i][a[i]]++;
    }
    long long ans = 0;
    for (int j = 0; j < n; j++) {
        if (s[j] == 'E') {
            for (int v1 = 0; v1 < 3; v1++) {
                for (int v2 = 0; v2 < 3; v2++) {
                    long long count = pre[j][v1] * suf[j + 1][v2];
                    ans += count * mx(v1, a[j], v2);
                }
            }
        }
    }
    cout << ans << endl;


    return 0;
}