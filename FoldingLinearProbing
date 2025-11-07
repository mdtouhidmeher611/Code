#include <iostream>
using namespace std;

const int SIZE = 11;

// Folding Method Hash Function
int foldingHash(int key) {
    int sum = 0;
    while (key > 0) {
        sum += key % 100; // Add last two digits
        key /= 100;
    }
    return sum % SIZE;
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

    // Insert using linear probing
    for (int i = 0; i < n; i++) {
        int key = data[i];
        int index = foldingHash(key);

        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }
        hashTable[index] = key;
    }

    cout << "\nHash Table (Folding + Linear Probing):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        if (hashTable[i] != -1) cout << hashTable[i];
        cout << endl;
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int index = foldingHash(searchKey);
    int start = index;
    bool found = false;

    while (hashTable[index] != -1) {
        if (hashTable[index] == searchKey) {
            found = true;
            break;
        }
        index = (index + 1) % SIZE;
        if (index == start) break;
    }

    if (found)
        cout << searchKey << " found at index " << index << endl;
    else
        cout << "Element not found.\n";

    return 0;
}
