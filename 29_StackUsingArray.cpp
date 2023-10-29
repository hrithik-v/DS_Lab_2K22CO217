// 29. Stack implementation using array.

#include <iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int X){
        size = X;
        arr = new int(size);
        top = -1;
    }

    void push(int X){
        if (top == size-1){
            cout<<"Stack Overflow";
            return;
        }
        arr[++top] = X;
        return;
    }

    void pop(){
        if (top==-1){
            cout<<"Stack Underflow";
            return;
        }
        top--;
        return;
    }

    void Top(){
        if (top==-1){
            cout<<"Stack Empty";
            return;
        }
        cout<<arr[top]<<endl;
    }
};

int main(){
    Stack s(50);    //  Stack of Size 50

    s.push(12);
    s.push(1);
    s.push(62);

    s.pop();
    s.Top();    // -> 1
    s.pop();
    s.Top();    // -> 12
    s.pop();
    s.Top();    // -> Empty
    
    cout<<"\n---------\n";
    s.pop();

}