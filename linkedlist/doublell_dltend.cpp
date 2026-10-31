
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
    int n;

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

    if (head == NULL)
        cout << "List is empty";
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
    }

    cout << "\nList after deletion: ";
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
