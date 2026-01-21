#include <bits/stdc++.h>
using namespace std;

int n, q;
int rc[100005], cc[100005];
int rb[100005], cb[100005];

void up(int* b, int i, int v) {
    for (; i <= n; i += i & -i) {
        b[i] += v;
    }
}

int qr(int* b, int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) {
        s += b[i];
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n >> q)) 
        return 0;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            if (++rc[x] == 1) 
                up(rb, x, 1);
            if (++cc[y] == 1) 
                up(cb, y, 1);
        } 
        else if (t == 2) {
            int x, y;
            cin >> x >> y;
            if (--rc[x] == 0) 
                up(rb, x, -1);
            if (--cc[y] == 0) 
                up(cb, y, -1);
        } 
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bool rok = (qr(rb, x2) - qr(rb, x1 - 1)) == (x2 - x1 + 1);
            bool cok = (qr(cb, y2) - qr(cb, y1 - 1)) == (y2 - y1 + 1);
            if (rok || cok) 
                cout << "Yes\n";
            else 
            cout << "No\n";
        }
    }

    return 0;
}