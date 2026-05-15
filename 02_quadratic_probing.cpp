#include <iostream>
using namespace std;

int main() {
    int hashTable[10];
    for(int i=0;i<10;i++) hashTable[i] = -1;

    int arr[] = {23, 43, 13, 27};
    for(int i=0;i<4;i++) {
        int key = arr[i];
        int index = key % 10;
        int j = 1;

        while(hashTable[index] != -1) {
            index = (key % 10 + j*j) % 10;
            j++;
        }

        hashTable[index] = key;
    }

    for(int i=0;i<10;i++)
        cout << i << " -> " << hashTable[i] << endl;
}