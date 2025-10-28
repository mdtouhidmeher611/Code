#include <bits/stdc++.h>
using namespace std;

long long isqrt(long long x) {
    long long low = 0, high = 3000000000LL;
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if (mid * mid <= x) low = mid;
        else high = mid - 1;
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    while (n--) {
        long long s;
        cin >> s;
        long long m = isqrt(1 + 8 * s);
        long long k = (m - 1) / 2;
        cout << k << "\n";
    }
    return 0;
}