// array_operations.cpp
#include <iostream>
using namespace std;

class ArrayOperations {
private:
    int* arr;
    int capacity;
    int size;

public:
    ArrayOperations(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    void insert(int value, int position) {
        if (size == capacity) {
            cout << "Array is full!" << endl;
            return;
        }

        if (position < 0 || position > size) {
            cout << "Invalid position!" << endl;
            return;
        }

        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }

        arr[position] = value;
        size++;
        cout << "Inserted " << value << " at position " << position << endl;
    }

    void deleteAtPosition(int position) {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }

        if (position < 0 || position >= size) {
            cout << "Invalid position!" << endl;
            return;
        }

        cout << "Deleted " << arr[position] << " from position " << position << endl;

        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void traverse() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~ArrayOperations() {
        delete[] arr;
    }
};

int main() {
    ArrayOperations arr(10);

    arr.insert(10, 0);
    arr.insert(20, 1);
    arr.insert(30, 2);
    arr.insert(15, 1);
    arr.traverse();

    arr.deleteAtPosition(2);
    arr.traverse();

    arr.insert(25, 2);
    arr.traverse();

    return 0;
}
