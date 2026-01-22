#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) 
        cin >> s[i];
    if (s[0][0] != 's') {
        cout << "No" << endl;
        return 0;
    }
    string target = "snuke";
    map<char, char> next_char;
    for (int i = 0; i < 5; i++) {
        next_char[target[i]] = target[(i + 1) % 5];
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    q.push({0, 0});
    vis[0][0] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if (r == h - 1 && c == w - 1) {
            cout << "Yes" << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && !vis[nr][nc]) {
                if (s[nr][nc] == next_char[s[r][c]]) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}