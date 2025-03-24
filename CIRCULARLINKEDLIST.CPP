#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        cout << "ELEMENTS: " << ptr->data << endl;
        ;
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    cout << "ELEMENTS OF CIRCULAR LINKED LIST ARE: " << endl;
    node *head = new node();
    node *second = new node();
    node *third = new node();
    node *fourth = new node();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = head;

    traversal(head);

    return 0;
}
