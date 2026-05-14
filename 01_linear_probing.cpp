#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for(int i = 0; i < SIZE; i++) {
            table[i] = -1;
        }
    }

    // Insert element using linear probing
    void insert(int key) {
        int index = key % SIZE;

        // Linear probing
        while(table[index] != -1) {
            index = (index + 1) % SIZE;
        }

        table[index] = key;
    }

    // Display hash table
    void display() {
        cout << "\nHash Table:\n";

        for(int i = 0; i < SIZE; i++) {
            cout << i << " --> ";

            if(table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main() {
    HashTable h;

    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> value;
        h.insert(value);
    }

    h.display();

    return 0;
}
