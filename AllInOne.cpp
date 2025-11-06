#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 11; // Prime size
int dataArr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
int n = 9;

// Function for Linear Probing
void linearProbing() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;

    for (int i = 0; i < n; i++) {
        int key = dataArr[i];
        int index = key % SIZE;

        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }
        hashTable[index] = key;
    }

    cout << "\nHash Table (Linear Probing):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        if (hashTable[i] != -1) cout << hashTable[i];
        cout << endl;
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int index = searchKey % SIZE, start = index;
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
        cout << searchKey << " not found.\n";
}

// Function for Plus 3 Probing
void plus3Probing() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;

    for (int i = 0; i < n; i++) {
        int key = dataArr[i];
        int index = key % SIZE;

        while (hashTable[index] != -1) {
            index = (index + 3) % SIZE;
        }
        hashTable[index] = key;
    }

    cout << "\nHash Table (Plus 3 Probing):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        if (hashTable[i] != -1) cout << hashTable[i];
        cout << endl;
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int index = searchKey % SIZE, start = index;
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
        cout << searchKey << " not found.\n";
}

// Function for Quadratic Probing
void quadraticProbing() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;

    for (int i = 0; i < n; i++) {
        int key = dataArr[i];
        int hash = key % SIZE;
        int j = 0, index = hash;

        while (hashTable[index] != -1) {
            j++;
            index = (hash + j * j) % SIZE;
        }
        hashTable[index] = key;
    }

    cout << "\nHash Table (Quadratic Probing):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        if (hashTable[i] != -1) cout << hashTable[i];
        cout << endl;
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int hash = searchKey % SIZE, j = 0, index;
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
        cout << searchKey << " not found.\n";
}

// Function for Chaining
void chaining() {
    vector<int> hashTable[SIZE];

    for (int i = 0; i < n; i++) {
        int key = dataArr[i];
        int index = key % SIZE;
        hashTable[index].push_back(key);
    }

    cout << "\nHash Table (Chaining):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        for (int val : hashTable[i]) cout << val << " -> ";
        cout << "NULL\n";
    }

    int searchKey;
    cout << "\nEnter element to search: ";
    cin >> searchKey;

    int index = searchKey % SIZE;
    bool found = false;

    for (int val : hashTable[index]) {
        if (val == searchKey) {
            found = true;
            break;
        }
    }

    if (found)
        cout << searchKey << " found in chain at index " << index << endl;
    else
        cout << searchKey << " not found.\n";
}

// Main Menu
int main() {
    int choice;
    do {
        cout << "\n====== HASH TABLE MENU ======\n";
        cout << "1. Linear Probing\n";
        cout << "2. Plus 3 Probing\n";
        cout << "3. Quadratic Probing\n";
        cout << "4. Chaining\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: linearProbing(); break;
            case 2: plus3Probing(); break;
            case 3: quadraticProbing(); break;
            case 4: chaining(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
