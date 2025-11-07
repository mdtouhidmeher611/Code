#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int SIZE = 11;

// Character-based Hash Function
int charHash(string key) {
    int sum = 0;
    for (char c : key) sum += (int)c;
    return sum % SIZE;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> data(n);
    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++) cin >> data[i];

    vector<string> hashTable[SIZE];

    // Insert using chaining
    for (string key : data) {
        int index = charHash(key);
        hashTable[index].push_back(key);
    }

    cout << "\nHash Table (Character-Based + Chaining):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        for (string val : hashTable[i])
            cout << val << " -> ";
        cout << "NULL\n";
    }

    string searchKey;
    cout << "\nEnter string to search: ";
    cin >> searchKey;

    int index = charHash(searchKey);
    bool found = false;

    for (string val : hashTable[index]) {
        if (val == searchKey) {
            found = true;
            break;
        }
    }

    if (found)
        cout << searchKey << " found in chain at index " << index << endl;
    else
        cout << "String not found.\n";

    return 0;
}
