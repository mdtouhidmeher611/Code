#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long k;
    cin >> k;
    string s = "";
    while (k > 0) {
        if (k % 2 == 1) 
            s += '2';
        else 
            s += '0';
        k /= 2;
    }

    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}


 