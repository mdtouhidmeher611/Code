#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {10, 5, 20, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    cout << "Maximum value: " << maxVal << endl;

    return 0;
}
