// linear_search.cpp
#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        cout << "Element " << key << " found at index " << result << endl;
    } else {
        cout << "Element " << key << " not found" << endl;
    }

    return 0;
}
