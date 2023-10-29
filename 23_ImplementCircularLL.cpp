// 23. Circular Linked List Implementation

#include <iostream>
using namespace std;

// Circular Linked List Node
class Node {
    public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class CircularLinkedList {
    Node* head;

    public:
    CircularLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the beginning of the circular linked list
    void insertAtBegin(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Making it point to itself for the circular property.
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Function to insert a node at the end of the circular linked list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Making it point to itself for the circular property.
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    // Function to print the circular linked list
    void print() {
        if (head == NULL) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtBegin(1);
    cll.insertAtBegin(2);
    cll.insertAtEnd(3);
    cll.insertAtEnd(4);

    cout << "Circular Linked List: ";
    cll.print();

    return 0;
}
