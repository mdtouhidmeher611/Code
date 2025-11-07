#include <iostream>
#include <string>
using namespace std;

const int SIZE = 11;

// Mid-Square Hash Function
int midSquareHash(int key) {
    long long square = (long long)key * key;
    string s = to_string(square);
    int len = s.length();
    string mid;
    if (len % 2 == 0)
        mid = s.substr(len / 2 - 1, 2);
    else
        mid = s.substr(len / 2, 2);
    int midVal = stoi(mid);
    return midVal % SIZE;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int data[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> data[i];

    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;

    // Insert using plus 3 probing
    for (int i = 0; i < n; i++) {
        int key = data[i];
        int index = midSquareHash(key);

        while (hashTable[index] != -1) {
            index = (index + 3) % SIZE;
        }
        hashTable[index] = key;
    }

    cout << "\nHash Table (Mid-Square + Plus 3 Probing):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        if (hashTable[i] != -1) cout << hashTable[i];
        cout << endl;
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int index = midSquareHash(searchKey);
    int start = index;
    bool found = false;

    while (hashTable[index] != -1) {
        if (hashTable[index] == searchKey) {
            found = true;
            break;
        }
        index = (index + 3) % SIZE;
        if (index == start) break;
    }

    if (found)
        cout << searchKey << " found at index " << index << endl;
    else
        cout << "Element not found.\n";

    return 0;
}
