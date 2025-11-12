#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {0, 30, 45, 60, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << fixed << setprecision(4);
    for (int i = 0; i < n; i++) {
        double radians = arr[i] * M_PI / 180.0;
        double sinVal = sin(radians);
        cout << "sin(" << arr[i] << "°) = " << sinVal << endl;
    }

    return 0;
}
