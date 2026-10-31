
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node *head = NULL, *temp, *newnode;
    int n, pos, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        newnode = new Node;
        cin >> newnode->data;
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
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
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;

        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;
    }

    cout << "Linked list: ";
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
