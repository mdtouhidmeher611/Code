#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void calculate() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n), p(n + 1, 0);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        p[i + 1] = p[i] + b[i];
    }
    vector<long long> ct(n + 1, 0), rm(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int j = upper_bound(p.begin(), p.end(), a[i] + p[i]) - p.begin() - 1;
        ct[i]++;
        if (j < n + 1) 
            ct[j]--;
        if (j < n) 
            rm[j] += a[i] - (p[j] - p[i]);
    }
    long long cr = 0;
    for (int i = 0; i < n; i++) {
        cr += ct[i];
        cout << (cr * b[i]) + rm[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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