// singly_linked_list.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at beginning" << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at end" << endl;
    }

    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Position out of range!" << endl;
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at position " << position << endl;
    }

    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Deleted " << value << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value not found!" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Deleted " << value << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Linked List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtPosition(15, 2);
    list.display();

    list.deleteNode(20);
    list.display();

    return 0;
}
