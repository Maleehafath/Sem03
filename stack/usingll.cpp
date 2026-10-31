#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    
    Stack() {
        top = nullptr;
    }

    void push(int x);
    int pop();
    int isEmpty(); 
};


void Stack::push(int x) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
        cout << "Heap Overflow! Memory allocation failed.\n";
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    cout << x << " pushed into stack\n";
}


int Stack::pop() {
    if (top == nullptr) {
        cout << "Stack Underflow! No elements to pop\n";
        return -1;
    } else {
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp; 
        return poppedValue;
    }
}

int Stack::isEmpty() {
    if (top == nullptr) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    Stack s;

    
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " popped from stack\n";
    
    cout << s.pop() << " popped from stack\n";

    return 0;
}