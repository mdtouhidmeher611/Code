#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    sort(prices.begin(), prices.end());
    
    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        
        int left = 0, right = n - 1;
        int count = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (prices[mid] <= m) {
                count = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}