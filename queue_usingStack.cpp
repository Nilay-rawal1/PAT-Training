#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> stack1, stack2;

    // Transfer elements from stack1 to stack2
    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    // Enqueue an element to the queue
    void enqueue(int x) {
        stack1.push(x);
    }

    // Dequeue an element from the queue
    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                throw std::out_of_range("Queue is empty");
            }
            transferStack1ToStack2();
        }
        int topVal = stack2.top();
        stack2.pop();
        return topVal;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    // Get the front element of the queue
    int front() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                throw std::out_of_range("Queue is empty");
            }
            transferStack1ToStack2();
        }
        return stack2.top();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element is: " << queue.front() << std::endl; // Should print 1
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;      // Should print 1
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;      // Should print 2

    queue.enqueue(4);

    std::cout << "Front element is: " << queue.front() << std::endl; // Should print 3
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;      // Should print 3
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;      // Should print 4

    if (queue.isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << "Queue is not empty" << std::endl;
    }

    return 0;
}
