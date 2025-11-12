#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {10, 5, 20, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    double average = (double)sum / n;
    cout << "Average value: " << average << endl;

    return 0;
}

