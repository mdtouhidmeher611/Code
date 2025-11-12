#include <bits/stdc++.h>
using namespace std;

int binarySearchString(string arr[], int size, string target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    string words[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    int size = sizeof(words) / sizeof(words[0]);
    string target = "date";

    int index = binarySearchString(words, size, target);

    if (index != -1)
        cout << "Found '" << target << "' at index " << index << endl;
    else
        cout << "String '" << target << "' not found " << endl;

    return 0;
}

