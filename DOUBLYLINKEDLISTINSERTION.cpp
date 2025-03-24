#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *insert_AT_start(struct node *head, int data)
{
    struct node *ptr = new node;

    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;

    // if (head != nullptr)
    // {
    //     head->prev = ptr;
    // }
    return ptr;
}
// case:2
struct node *insert_in_middle(struct node *head, int index, int data)
{
    struct node *ptr = new node;
    struct node *q = head;
    for (int i = 0; i < index - 1; i++)
    {
        q = q->next;
    }
    ptr->data = data;
    ptr->next = q->next;
    q->next = ptr;
    return head;
}
struct node *insert_at_end(struct node *head, int data)
{
    struct node *ptr = new node;
    struct node *q = head;
    ptr->data = data;
    while (q->next != nullptr)
    {
        q = q->next;
    }

    ptr->next = q->next;
    q->next = ptr;
    return head;
}

void traversal(struct node *ptr)
{
    cout << "ELEMENTS OF LINK LIST A:" << endl;

    while (ptr != NULL)
    {
        cout << "ELEMENTS :" << ptr->data << endl;
        ptr = ptr->next;
    }
}
void Backward_traversal(struct node *ptr)
{

    cout << "ELEMENTS IN BACKWARD DIRECTION: " << endl;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        cout << "ELEMENTS: " << ptr->data << endl;
        ptr = ptr->prev;
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

    // Backward_traversal(head);

    // cout << "AFTER INSERTION" << endl;
    // head = insert_AT_start(head, 5);
    // traversal(head);

    // cout << "AFTER INSERTION" << endl;
    // head = insert_in_middle(head, 2, 5);
    // traversal(head);

    cout << "AFTER INSERTION" << endl;
    head = insert_at_end(head, 60);
    traversal(head);

    return 0;
}