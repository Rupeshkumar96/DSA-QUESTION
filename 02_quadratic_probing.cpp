// quadratic_probing_hash.cpp
#include <iostream>
#include <vector>
using namespace std;

class QuadraticProbingHash {
private:
    vector<int> table;
    int capacity;
    int size;

public:
    QuadraticProbingHash(int cap) {
        capacity = cap;
        size = 0;
        table.resize(capacity, -1);
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Hash table is full!" << endl;
            return;
        }

        int index = hashFunction(key);
        int i = 1;

        while (table[index] != -1) {
            index = (hashFunction(key) + i*i) % capacity;
            i++;
        }

        table[index] = key;
        size++;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int i = 1;

        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (hashFunction(key) + i*i) % capacity;
            i++;
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
    QuadraticProbingHash hash(10);

    hash.insert(15);
    hash.insert(25);
    hash.insert(35);
    hash.insert(5);
    hash.insert(45);

    hash.display();

    cout << "Search 25: " << (hash.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}
