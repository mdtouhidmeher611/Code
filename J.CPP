#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<int> p(m + 1, 0);
    vector<int> q(m + 1, 0);

    auto ok = [](char a, char b) {
        return a == '?' || b == '?' || a == b;
    };

    p[0] = 1;
    for (int i = 1; i <= m; i++) {
        if (ok(s[i - 1], t[i - 1])) p[i] = p[i - 1];
        else                        
            break;
    }

    q[0] = 1;
    for (int i = 1; i <= m; i++) {
        if (ok(s[n - i], t[m - i])) q[i] = q[i - 1];
        else                        
            break;
    }

    for (int x = 0; x <= m; x++) {
        if (p[x] && q[m - x]) 
            cout << "Yes\n";
        else                  
            cout << "No\n";
    }

    return 0;
}