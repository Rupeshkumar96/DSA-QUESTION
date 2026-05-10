/*A straming systen always needs snallest element quickly
implement min Heap(insert + delete operations)*/

#include <iostream>
using namespace std;
int heap[100];
int size = 0;
void insert(int val) {
    size++;
    int i = size - 1;
    heap[i] = val;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}
void deleteMin() {
    if (size <= 0) return;
    if (size == 1) {
        size--;
        return;
    }
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}

int main() {
    insert(15);
    insert(5);
    insert(20);
    insert(2);

    cout << "Smallest element: " << heap[0] << endl;

    deleteMin();
    cout << "Next smallest: " << heap[0] << endl;

    return 0;
}
