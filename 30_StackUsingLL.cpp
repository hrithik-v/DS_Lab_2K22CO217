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

class Stack{
    Node* top;
    // I took 1 Pointer that point at top of stack i.e at end of LL
    public: 

    Stack(){
        top = NULL;
    }

    void push(int X){
        if (top== NULL){
            top = new Node(X);
            return;
        }
        Node * temp = new Node(X);
        temp->next = top;
        top = temp;
        return;        
    }

    void pop(){
        if (top == NULL){
            cout<<"Queue Underflow";
            return;
        }

        Node *temp = top;
        top = top->next;
        
        // deallocate memory
        delete temp;
        return; 
    }

    void Top(){
        cout<<top->data<<endl;
        return;
    }
};


int main(){

    Stack s;
    s.push(12);
    s.push(98);
    s.push(1);
    s.Top();
    s.pop();
    s.Top();


    return 0;
}
