
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node *head = NULL, *newnode, *temp;
    int choice = 1;

    while(choice == 1)
    {
        newnode = new Node;

        cout << "Enter data: ";
        cin >> newnode->data;

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->next = head;
        }

        cout << "Do you want to continue? (1/0): ";
        cin >> choice;
    }

    cout << "\nCircular Linked List: ";

    temp = head;

    if(head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != head);
    }

    return 0;
}
