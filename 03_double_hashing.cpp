// double_hashing_hash.cpp
#include <iostream>
#include <vector>
using namespace std;

class DoubleHashingHash {
private:
    vector<int> table;
    int capacity;
    int size;

    int hash1(int key) {
        return key % capacity;
    }

    int hash2(int key) {
        return 7 - (key % 7); // Second hash function
    }

public:
    DoubleHashingHash(int cap) {
        capacity = cap;
        size = 0;
        table.resize(capacity, -1);
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Hash table is full!" << endl;
            return;
        }

        int index = hash1(key);
        int stepSize = hash2(key);

        while (table[index] != -1) {
            index = (index + stepSize) % capacity;
        }

        table[index] = key;
        size++;
    }

    bool search(int key) {
        int index = hash1(key);
        int stepSize = hash2(key);

        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + stepSize) % capacity;
        }
        return false;
    }

    void display() {
        cout << "Hash Table: ";
        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1)
                cout << i << ":" << table[i] << " ";
            else
                cout << i << ":- ";
        }
        cout << endl;
    }
};

int main() {
    DoubleHashingHash hash(10);

    hash.insert(15);
    hash.insert(25);
    hash.insert(35);
    hash.insert(5);
    hash.insert(45);

    hash.display();

    cout << "Search 35: " << (hash.search(35) ? "Found" : "Not Found") << endl;

    return 0;
}
