// stack_array.cpp
#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed: " << value << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.pop();
    s.display();

    s.push(40);
    s.display();

    return 0;
}
