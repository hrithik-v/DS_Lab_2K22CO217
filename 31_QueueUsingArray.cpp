// 31. Queue implementation using array 

#include <iostream>
using namespace std;

class Queue{
    int size;
    int *arr;
    int front;
    int rear;

    public:
    // Constructor
    Queue(int n){
        size = n;
        front = rear = -1;
        arr = new int(size);
    }

    void push(int X){
        // cout<<size<<endl;
        if (front==-1){
            front++;
            // rear++;
            arr[++rear] = X;
            return;
        }
        
        if (front == (rear+1)%size){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        else{
            rear = (rear+1)%size;
        }
        
        arr[rear] = X;
        return;
    }

    void pop(){
        if (front==-1)
            cout<<"Queue Underflow"<<endl;
        else if (front == rear){
            front = rear = -1;
        }
        else{
            cout<<"Popped: "<<arr[front]<<endl;
            front = (front+1)%size;
        }
        return;
    }

    void Front(){
        if (front == -1){
            cout<<"Queue Empty";
            return;
        }
        cout<<arr[front]<<endl;
        return;
    }

    bool isEmpty(){
        if (front==-1)
            return true;
        return false;
    }

};


int main(){

    Queue q(4);
    q.push(2);
    
    q.push(1);
    q.push(4);
    q.push(5);
    q.Front();

    // q.pop();

    q.Front();
    q.pop();
    q.push(19);
    q.Front();
    q.push(10);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    
    q.pop();
    
}