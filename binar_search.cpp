#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 40;

    int low = 0, high = n - 1;
    int position = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            position = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (position != -1) {
        cout << "Element " << target << " found at index " << position << endl;
    } else {
        cout << "Element " << target << " not found in the array " << endl;
    }

    return 0;
}
