#include <iostream>
using namespace std;

int main() {
    const int size = 11;
    int hashTable[size];
    for (int i = 0; i < size; i++) hashTable[i] = -1;

    int data[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = 9;

    for (int i = 0; i < n; i++) {
        int key = data[i];
        int index = key % size;

        while (hashTable[index] != -1) {
            index = (index + 3) % size;
        }
        hashTable[index] = key;
    }

    cout << "Hash Table (Plus 3 Probing):\n";
    for (int i = 0; i < size; i++) {
        cout << i << " : ";
        if (hashTable[i] != -1) cout << hashTable[i];
        cout << endl;
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int index = searchKey % size;
    int start = index;
    bool found = false;

    while (hashTable[index] != -1) {
        if (hashTable[index] == searchKey) {
            found = true;
            break;
        }
        index = (index + 3) % size;
        if (index == start) break;
    }

    if (found)
        cout << searchKey << " found at index " << index << endl;
    else
        cout << searchKey << " not found.\n";

    return 0;
}
