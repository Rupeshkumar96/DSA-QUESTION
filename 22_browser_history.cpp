// browser_history.cpp
#include <iostream>
#include <string>
using namespace std;

struct HistoryNode {
    int pageId;
    string url;
    HistoryNode* next;
};

class BrowserHistory {
private:
    HistoryNode* head;

public:
    BrowserHistory() {
        head = NULL;
    }

    void addPage(int id, string url) {
        HistoryNode* newNode = new HistoryNode;
        newNode->pageId = id;
        newNode->url = url;
        newNode->next = head;
        head = newNode;
        cout << "Added page: " << url << " (ID: " << id << ")" << endl;
    }

    void displayHistory() {
        if (head == NULL) {
            cout << "Browsing history is empty!" << endl;
            return;
        }

        cout << "\nBrowsing History (most recent first):" << endl;
        HistoryNode* temp = head;
        int position = 1;
        while (temp != NULL) {
            cout << position++ << ". ID: " << temp->pageId << " - " << temp->url << endl;
            temp = temp->next;
        }
    }
};

int main() {
    BrowserHistory history;

    history.addPage(101, "https://www.google.com");
    history.addPage(102, "https://www.github.com");
    history.addPage(103, "https://stackoverflow.com");
    history.addPage(104, "https://www.cppreference.com");

    history.displayHistory();

    return 0;
}
