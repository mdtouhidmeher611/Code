#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<long long> f(1024, 0);
    int m = 0;
    f[m]++;

    long long r = 0;
    for (char c : s) {
        m ^= (1 << (c - '0'));
        r += f[m];
        f[m]++;
    }

    cout << r << endl;

    return 0;
}