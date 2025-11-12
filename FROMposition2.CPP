#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    int pos = 2;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return 1;
    }


    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;


    cout << "Array after deleting item at position " << pos << ":\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
