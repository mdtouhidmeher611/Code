
#include <bits/stdc++.h>
using namespace std;

int main() {
    string arr[10] = {"Ali", "Babar", "Kamran", "Naveed", "Omar", "Rahim"};
    int n = 6;
    int capacity = 10;
    string value = "Karim";
    int pos = 5;
    if (pos > n || pos < 0) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;

    cout << "Array after inserting \"" << value << "\" at position " << pos << ":\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
