#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int capacity = 10;
    int value = 54;


    int pos = 0;
    while (pos < n && arr[pos] < value) {
        pos++;
    }


    for (int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }


    arr[pos] = value;
    n++;


    cout << "Array after inserting " << value << ":\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

