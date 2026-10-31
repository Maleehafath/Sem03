#include <iostream>
using namespace std;

// Define structure for the linked list node
struct Node {
    int data;
    Node* next;
};

class Queue {
    Node *front, *rear;

public:
    // Constructor to initialize front and rear pointers
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int x);
    int dequeue();
    int isEmpty(); // Returns 1 if empty, 0 if not empty
};

// Function to add an element to the queue (Enqueue)
void Queue::enqueue(int x) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
        cout << "Heap Overflow! Memory allocation failed.\n";
        return;
    }
    newNode->data = x;
    newNode->next = nullptr;

    // If the queue is empty, the new node is both front and rear
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        // Add the new node at the end and update rear
        rear->next = newNode;
        rear = newNode;
    }
    cout << x << " enqueued to queue\n";
}

// Function to remove an element from the queue (Dequeue)
int Queue::dequeue() {
    if (front == nullptr) {
        cout << "Queue Underflow! No elements to dequeue\n";
        return -1;
    }

    Node* temp = front;
    int x = temp->data;
    
    // Move front pointer to the next node
    front = front->next;

    // If front becomes null, the queue is now empty, so update rear to null as well
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp; // Free memory of the dequeued node
    return x;
}

// Function to check if the queue is empty (returns 1 for true, 0 for false)
int Queue::isEmpty() {
    if (front == nullptr) {
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