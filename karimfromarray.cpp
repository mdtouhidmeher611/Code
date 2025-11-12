#include <bits/stdc++.h>
using namespace std;

int main() {
    string arr[10] = {"Ali", "Babar", "Kamran", "Karim", "Naveed", "Omar", "Rahim"};
    int n = 7;
    string value = "Karim";


    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "\"" << value << "\" not found in the array." << endl;
        return 0;
    }


    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Array after deleting \"" << value << "\":" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

