#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;

public:
    int arr[MAX]; 
    Stack() { 
        top = -1; 
    }

    void push(int x);
    int pop();
    int isEmpty(); 
};

void Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow! Cannot push " << x << "\n";
    } else {
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow! No elements to pop\n";
        return -1;
    } else {
        int x = arr[top--];
        return x;
    }
}


int Stack::isEmpty() {
    if (top < 0) {
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