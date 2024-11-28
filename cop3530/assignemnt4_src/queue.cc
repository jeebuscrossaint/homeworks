#include "assignment4.hh"

using namespace queue;

Queue::Queue(): front(-1), rear (-1) {};
Queue::~Queue() {};

void Queue::enqueue(int val) {
        rear++;
        arr[rear] = val;
}

int Queue::dequeue() {
        int ans = arr[front];
        front++;

        return ans;
}

void Queue::display() {
        std::cout << "Queue:  ";
        for (int i = front; i <= rear; i++) {
                std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
}

int main() {
        Queue q;

        // enqueue time
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        std::cout << "\n Initial enqueue:" << std::endl;

        q.display();

        // more enqueing
        q.enqueue(4);
        q.enqueue(5);

        std::cout << "\n Post second enqueue (enqueued 4 and 5):" << std::endl;
        q.display();

        // queue overflow
        //q.enqueue(6);

        // dequeuing
        std::cout << "\nDequeueing elements:" << std::endl;
        std::cout << "Dequeued element: " << q.dequeue() << std::endl; 
        std::cout << "Dequeued element: " << q.dequeue() << std::endl;

        // post dequue display
        std::cout << "\n Post dequeue (dequeued 0 and 1):" << std::endl;
        q.display();

        return 0;
}