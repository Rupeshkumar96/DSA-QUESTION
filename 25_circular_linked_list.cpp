// circular_linked_list.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << "Inserted " << value << endl;
    }

    void display() {
        if (last == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Circular Linked List: ";
        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();

    return 0;
}
