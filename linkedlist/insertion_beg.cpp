
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node *head, *newnode, *temp;

    head = new Node;
    head->data = 10;
    head->next = NULL;

    newnode = new Node;

    cout << "Enter data for new node: ";
    cin >> newnode->data;

    newnode->next = head;
    head = newnode;

    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
