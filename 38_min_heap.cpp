// min_heap.cpp
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Inserted " << value << " into Min Heap" << endl;
    }

    void deleteMin() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "Deleted minimum element: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    void display() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "Min Heap: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }

    int getMin() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }
};

int main() {
    MinHeap heap;

    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(3);
    heap.insert(8);

    heap.display();
    cout << "Minimum element: " << heap.getMin() << endl;

    heap.deleteMin();
    heap.display();

    heap.insert(2);
    heap.display();

    return 0;
}
