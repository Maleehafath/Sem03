
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

    int n, pos;

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

    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == NULL)
        cout << "List is empty";
    else if (pos == 1)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL)
            cout << "Invalid position";
        else
        {
            Node* delnode = temp->next;
            temp->next = delnode->next;
            delete delnode;
        }
    }

    cout << "\nLinked list after deletion: ";
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
