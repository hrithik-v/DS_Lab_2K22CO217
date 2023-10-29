#include <iostream>

using namespace std;

// Definition for a singly-linked list.
class Node {
    public:
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

// Function to detect and remove a cycle in a linked list
bool detectAndRemoveCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false; // No cycle if there are 0 or 1 nodes.
    }

    Node* tortoise = head;
    Node* hare = head;
    Node* prev = NULL;

    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare) {
            // Cycle detected.
            tortoise = head;
            while (tortoise != hare) {
                tortoise = tortoise->next;
                prev = hare;
                hare = hare->next;
            }
            prev->next = NULL; // Remove the cycle.
            return true;
        }
    }

    return false; // No cycle detected.
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a linked list with a cycle
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3; // Create a cycle

    bool hasCycle = detectAndRemoveCycle(head);

    if (hasCycle) {
        cout << "Cycle detected and removed." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    cout << "Linked List after Cycle Removal:" << endl;
    printList(head);

    return 0;
}
