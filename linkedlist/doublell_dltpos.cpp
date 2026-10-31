
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
    int n, pos;

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

    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == NULL)
        cout << "List is empty";
    else if (pos == 1)
    {
        temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }
    else
    {
        temp = head;

        for (int i = 1; i < pos && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL)
            cout << "Invalid position";
        else
        {
            temp->prev->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            delete temp;
        }
    }

    cout << "List after deletion: ";
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
