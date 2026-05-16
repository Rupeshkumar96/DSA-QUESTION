#include <iostream>
using namespace std;

int hash2(int key) {
    return 7 - (key % 7);
}

int main() {
    int table[10];
    for(int i=0;i<10;i++) table[i] = -1;

    int arr[] = {23,43,13,27};

    for(int i=0;i<4;i++) {
        int key = arr[i];
        int index = key % 10;

        while(table[index] != -1)
            index = (index + hash2(key)) % 10;

        table[index] = key;
    }

    for(int i=0;i<10;i++)
        cout << i << " -> " << table[i] << endl;
}