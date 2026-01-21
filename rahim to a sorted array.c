 
#include <bits/stdc++.h>
using namespace std;

int main() {
    string arr[10] = {"Ali", "Babar", "Kamran", "Naveed", "Omar"};
    int n = 5;
    int capacity = 10;
    string value = "Rahim";


    int pos = 0;
    while (pos < n && arr[pos] < value) {
        pos++;
    }


    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;


    cout << "Array after inserting \"" << value << "\":\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
