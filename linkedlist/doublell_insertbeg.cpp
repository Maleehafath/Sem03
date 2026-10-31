
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
};

int main()
{
    Node *head = NULL, *temp, *newnode;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        newnode = new Node;

        cout << "Enter data: ";
        cin >> newnode->data;

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
        {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    cout << "Enter data to insert at beginning: ";
    cin >> x;

    newnode = new Node;
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;

    cout << "Doubly linked list: ";
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
