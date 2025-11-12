#include <bits/stdc++.h>
using namespace std;

int main() {
    string arr1[] = {"Ali", "Babar", "Kamran"};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    string arr2[] = {"Naveed", "Omar", "Rahim"};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    string arr3[n1 + n2];


    for (int i = 0; i < n1; i++) {
        arr3[i] = arr1[i];
    }

    for (int i = 0; i < n2; i++) {
        arr3[n1 + i] = arr2[i];
    }


    cout << "Merged string array: " ;
    for (int i = 0; i < n1 + n2; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}
