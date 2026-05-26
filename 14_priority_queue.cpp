// priority_queue_array.cpp
#include <iostream>
using namespace std;

struct Element {
    int data;
    int priority;
};

class PriorityQueue {
private:
    Element* arr;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        arr = new Element[capacity];
        size = 0;
    }

    void enqueue(int data, int priority) {
        if (size == capacity) {
            cout << "Priority Queue is full!" << endl;
            return;
        }

        Element newElem = {data, priority};
        int i = size - 1;

        while (i >= 0 && arr[i].priority < priority) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = newElem;
        size++;
        cout << "Enqueued: " << data << " (priority: " << priority << ")" << endl;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        cout << "Dequeued: " << arr[0].data << " (priority: " << arr[0].priority << ")" << endl;

        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue (data, priority): ";
        for (int i = 0; i < size; i++) {
            cout << "(" << arr[i].data << "," << arr[i].priority << ") ";
        }
        cout << endl;
    }

    ~PriorityQueue() {
        delete[] arr;
    }
};

int main() {
    PriorityQueue pq(5);

    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.enqueue(40, 1);
    pq.display();

    pq.dequeue();
    pq.display();

    return 0;
}
