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
        cout << "ELEMENTS " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}
// case1:

struct node *delete_at_start(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != head)
    {
        q = q->next;
    }

    q->next = p->next;
    head = head->next;
    delete (p);
    return head;
}

// case 2 :

struct node *delete_at_middle(struct node *head, int index)
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
// case3:

struct node *delete_at_end(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != head)
    {
        q = q->next;
        p = p->next;
    }

    p->next = q->next;
    delete (q);
    return head;
}

// case 4 :
struct node *delete_at_given_index(struct node *head, int key)
{

    struct node *p = head;
    struct node *q = head->next;

    while (q->data != key && q->next != head)
    {
        q = q->next;
        p = p->next;
    }

    p->next = q->next;
    delete (q);
    return head;
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

    // cout << "AFTER DELETION AT START:" << endl;
    // head = delete_at_start(head);
    // traversal(head);

    // cout << "AFTER DELETION AT MIDDLE:" << endl;
    // head = delete_at_middle(head ,2);
    // traversal(head);

    // cout << "AFTER DELETION AT END:" << endl;
    // head = delete_at_end(head);
    // traversal(head);

    cout << "AFTER DELETION AT GIVEN INDEX:" << endl;
    head = delete_at_given_index(head, 20);
    traversal(head);

    return 0;
}