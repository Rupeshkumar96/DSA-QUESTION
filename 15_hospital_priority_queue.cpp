// hospital_priority_queue.cpp
#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int severity; // Higher value = higher priority
};

class HospitalPriorityQueue {
private:
    Patient* heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].severity < heap[index].severity) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left].severity > heap[largest].severity) {
            largest = left;
        }
        if (right < size && heap[right].severity > heap[largest].severity) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    HospitalPriorityQueue(int cap) {
        capacity = cap;
        heap = new Patient[capacity];
        size = 0;
    }

    void addPatient(int id, string name, int severity) {
        if (size == capacity) {
            cout << "Hospital queue is full!" << endl;
            return;
        }

        heap[size] = {id, name, severity};
        size++;
        heapifyUp(size - 1);
        cout << "Added patient: " << name << " (Severity: " << severity << ")" << endl;
    }

    void treatPatient() {
        if (size == 0) {
            cout << "No patients waiting!" << endl;
            return;
        }

        Patient treated = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        cout << "Treating patient: " << treated.name << " (ID: " << treated.id
             << ", Severity: " << treated.severity << ")" << endl;
    }

    void displayWaitingList() {
        if (size == 0) {
            cout << "No patients waiting!" << endl;
            return;
        }

        cout << "\nPatients waiting (by priority):" << endl;
        for (int i = 0; i < size; i++) {
            cout << "ID: " << heap[i].id << ", Name: " << heap[i].name
                 << ", Severity: " << heap[i].severity << endl;
        }
    }

    ~HospitalPriorityQueue() {
        delete[] heap;
    }
};

int main() {
    HospitalPriorityQueue hospital(10);

    hospital.addPatient(101, "John Doe", 3);
    hospital.addPatient(102, "Jane Smith", 5);
    hospital.addPatient(103, "Bob Johnson", 2);
    hospital.addPatient(104, "Alice Brown", 4);

    hospital.displayWaitingList();

    hospital.treatPatient();
    hospital.treatPatient();

    hospital.displayWaitingList();

    return 0;
}
