// 38. Implement queue using stack

#include <iostream>
#include <stack>

class Queue {
    std::stack<int> stack1;
    std::stack<int> stack2;
    public:
    // Enqueue an element to the queue
    void enqueue(int x) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(x);
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    // Dequeue an element from the queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; 
        }
        int front = stack1.top();
        stack1.pop();
        return front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return stack1.empty();
    }

};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.enqueue(4);
    queue.enqueue(5);

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    return 0;
}
