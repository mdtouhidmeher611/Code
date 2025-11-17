#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;

        vector<int> cnt(7, 0);
        for (char c : a) {
            cnt[c - 'A']++;
        }

        int need = 0;
        for (int i = 0; i < 7; i++) {
            need += max(0, m - cnt[i]);
        }

        cout << need << "\n";
    }
    return 0;
}
