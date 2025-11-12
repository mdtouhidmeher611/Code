
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {10, 5, 20, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    cout << "Minimum value: " << minVal << endl;

    return 0;
}
