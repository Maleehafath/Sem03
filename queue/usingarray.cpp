#include <iostream>
using namespace std;

// Define the maximum size of the queue
#define MAX 100

class Queue {
    int front, rear;

public:
    int arr[MAX]; // Array to store queue elements

    // Constructor to initialize front and rear indices
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int x);
    int dequeue();
    int isEmpty(); // Returns 1 if empty, 0 if not empty
};

// Function to add an element to the queue (Enqueue)
void Queue::enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow! Cannot enqueue " << x << "\n";
        return;
    }
    if (front == -1) {
        front = 0; // First element being inserted
    }
    arr[++rear] = x;
    cout << x << " enqueued to queue\n";
}

// Function to remove an element from the queue (Dequeue)
int Queue::dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow! No elements to dequeue\n";
        return -1;
    }
    
    int x = arr[front++];
    
    // Reset queue if all elements have been dequeued
    if (front > rear) {
        front = -1;
        rear = -1;
    }
    
    return x;
}

// Function to check if the queue is empty (returns 1 for true, 0 for false)
int Queue::isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    } else {
        return 0;
    }
}

// Main function to test the queue operations
int main() {
    Queue q;

    // Enqueue elements into the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Dequeue an element from the queue
    cout << q.dequeue() << " dequeued from queue\n";
    
    // Dequeue another element
    cout << q.dequeue() << " dequeued from queue\n";

    return 0;
}