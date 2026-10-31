
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
    int n, x, pos;

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

    cout << "Enter data to insert: ";
    cin >> x;

    cout << "Enter position: ";
    cin >> pos;

    newnode = new Node;
    newnode->data = x;

    if (pos == 1)
    {
        newnode->prev = NULL;
        newnode->next = head;

        if (head != NULL)
            head->prev = newnode;

        head = newnode;
    }
    else
    {
        temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL)
            cout << "Invalid position";
        else
        {
            newnode->next = temp->next;
            newnode->prev = temp;

            if (temp->next != NULL)
                temp->next->prev = newnode;

            temp->next = newnode;
        }
    }

    cout << "Doubly linked list: ";
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
