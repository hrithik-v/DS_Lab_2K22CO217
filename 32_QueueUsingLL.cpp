// 32. Queue implementation using link list

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;

    Node(int X){
        data = X;
        next = NULL;
    }
};

class Queue{
    Node* start;
    Node* end;
    // I took 2 Pointers that point at front and back of LL
    public: 

    Queue(){
        start = end = NULL;
    }

    void push(int X){
        if (start == NULL){
            start = end = new Node(X);
            return;
        }
        end->next = new Node(X);
        end = end->next;
        return;        
    }

    void pop(){
        if (start == NULL){
            cout<<"Queue Underflow";
            return;
        }
        Node * temp = start;
        start = start->next;

        // deallocate memory
        delete temp;
        return; 
    }

    void front(){
        if (start==NULL){
            cout<<"Queue Empty";
            return;
        }
        cout<<start->data<<endl;
        return;
    }
};


int main(){

    Queue q;
    q.push(12);
    q.push(98);
    q.push(1);
    q.front();
    q.pop();
    q.pop();
    q.front();

    return 0;
}
