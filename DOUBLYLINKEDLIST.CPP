#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void Forward_traversal(struct node *ptr)
{
    cout << "ELEMENTS OF LINKED LIST IN FORWARD DIRECTION ARE AS FOLLOWING:" << endl;
    int index = 0;
    node *head = new node;
    while (ptr != NULL)
    {

        cout << " NEXT ELEMENT " << index << " : " << ptr->data << endl;

        ptr = ptr->next;

        index++;
    }
}
void Backward_traversal(struct node *ptr)
{
    node *head = new node;
    cout << "ELEMENTS OF LINKED LIST IN BACKWARD DIRECTION ARE AS FOLLOWING:" << endl;
    int ind = 0;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {

        cout << "ELEMENTS " << ind << " : " << ptr->data << endl;
        ptr = ptr->prev;
        ind++;
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

    Forward_traversal(head);
    cout << endl;

    Backward_traversal(head);
    return 0;
}