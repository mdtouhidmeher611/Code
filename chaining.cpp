#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int size = 11;
    vector<int> hashTable[size];

    int data[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = 9;

    // Insert using chaining
    for (int i = 0; i < n; i++) {
        int key = data[i];
        int index = key % size;
        hashTable[index].push_back(key);
    }

    cout << "Hash Table (Chaining):\n";
    for (int i = 0; i < size; i++) {
        cout << i << " : ";
        for (int val : hashTable[i]) cout << val << " -> ";
        cout << "NULL\n";
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int index = searchKey % size;
    bool found = false;

    for (int val : hashTable[index]) {
        if (val == searchKey) {
            found = true;
            break;
        }
    }

    if (found)
        cout << searchKey << " found at index " << index << endl;
    else
        cout << searchKey << " not found.\n";

    return 0;
}
