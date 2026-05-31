// delete_node_linkedlist.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Deleted from beginning" << endl;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        cout << "Deleted from end" << endl;
    }

    void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (position == 1) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Deleted at position " << position << endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Deleted at position " << position << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Original list: ";
    list.display();

    list.deleteAtBeginning();
    list.display();

    list.deleteAtEnd();
    list.display();

    list.deleteAtPosition(2);
    list.display();

    return 0;
}
