#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "ELEMENTS " << ptr->data << endl;
        ptr = ptr->next;
    }
}
void back_traversal(struct node *ptr)
{
    node *head = new node;
    cout << "ELEMENTS OF LINKED LIST IN BACKWARD DIRECTION" << endl;
    int index = 0;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    while (ptr != NULL)
    {
        cout << "ELEMENTS " << ptr->data << endl;
        ptr = ptr->prev;
        index++;
    }
}

int main()
{

    node *head = new node;
    node *second = new node;
    node *third = new node;
    node *fourth = new node;
    node *five = new node;

    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 40;
    fourth->next = five;

    five->prev = fourth;
    five->data = 50;
    five->next = NULL;

    traversal(head);

    cout << endl;

    back_traversal(head);
    return 0;
}