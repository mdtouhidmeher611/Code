#include <iostream>
#include <string>
using namespace std;

const int SIZE = 11;

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

    // Insert using quadratic probing
    for (int i = 0; i < n; i++) {
        int key = data[i];
        int hash = midSquareHash(key);
        int j = 0;
        int index = hash;

        while (hashTable[index] != -1) {
            j++;
            index = (hash + j * j) % SIZE;
        }
        hashTable[index] = key;
    }

    cout << "\nHash Table (Mid-Square + Quadratic Probing):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        if (hashTable[i] != -1) cout << hashTable[i];
        cout << endl;
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int hash = midSquareHash(searchKey);
    int j = 0;
    int index;
    bool found = false;

    while (true) {
        index = (hash + j * j) % SIZE;
        if (hashTable[index] == searchKey) {
            found = true;
            break;
        }
        if (hashTable[index] == -1 || j > SIZE) break;
        j++;
    }

    if (found)
        cout << searchKey << " found at index " << index << endl;
    else
        cout << "Element not found.\n";

    return 0;
}
