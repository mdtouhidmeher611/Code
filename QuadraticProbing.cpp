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
        int hash = key % size;

        int j = 0;
        int index = hash;
        while (hashTable[index] != -1) {
            j++;
            index = (hash + j * j) % size;
        }
        hashTable[index] = key;
    }

    cout << "Hash Table (Quadratic Probing):\n";
    for (int i = 0; i < size; i++) {
        cout << i << " : ";
        if (hashTable[i] != -1) cout << hashTable[i];
        cout << endl;
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int hash = searchKey % size;
    int j = 0;
    bool found = false;
    int index;

    while (true) {
        index = (hash + j * j) % size;
        if (hashTable[index] == searchKey) {
            found = true;
            break;
        }
        if (hashTable[index] == -1 || j > size) break;
        j++;
    }

    if (found)
        cout << searchKey << " found at index " << index << endl;
    else
        cout << searchKey << " not found.\n";

    return 0;
}
