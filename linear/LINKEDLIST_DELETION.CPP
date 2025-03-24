#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node *deletionatstart(struct node *head)
{
    // node * head = new node;
    struct node *ptr = head;
    head = head->next;
    delete (ptr);
    return head;
}
void traversal(struct node *ptr)
{
    cout << "THE ELEMENTS OF LINKED LIST ARE AS FOLLOWING:" << endl;
    int index = 0;
    while (ptr != NULL)
    {
        cout << "ELEMENTS " << index << " : " << ptr->data << endl;
        ptr = ptr->next;
        index++;
    }
}

struct node *deletioninmiddle(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    delete (q);
    return head;
}
struct node *deletionatend(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    delete (q);
    return head;
}
struct node *deletionofgivenkey(struct node *head, int key)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->data != key && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == key)
    {
        p->next = q->next;
        delete(q);
        return head;
    }
}
int main()
{
    node *head = new node;
    node *second = new node;
    node *Third = new node;
    node *fourth = new node;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = Third;

    Third->data = 30;
    Third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    traversal(head);
    cout << endl;

    // cout << "AFTER DELETION AT START: " << endl;
    // head = deletionatstart(head);
    // traversal(head);
    // cout << endl;

    // cout << "after deletion at middle: " << endl;
    // head = deletioninmiddle(head, 2);
    // traversal(head);
    // cout << endl;

    // cout << "After deletion at end of list : " << endl;
    // head = deletionatend(head);
    // traversal(head);
    // cout << endl;

    cout << "Atfer deletion of given key" << endl;
    head = deletionofgivenkey(head , 20);
    traversal(head);

    return 0;
}