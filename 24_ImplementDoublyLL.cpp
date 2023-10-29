#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Function to insert a node at the beginning of the DLL
    void insertAtBegin(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the end of the DLL
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to print the DLL from head to tail
    void printForward() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to print the DLL from tail to head
    void printBackward() {
        Node* current = tail;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtBegin(1);
    dll.insertAtBegin(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);

    cout << "Doubly Linked List (Forward): ";
    dll.printForward();
    
    cout << "Doubly Linked List (Backward): ";
    dll.printBackward();

    return 0;
}
