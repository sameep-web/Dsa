#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *ptr)
{
    cout << "ELEMENTS OF LINKED LIST ARE AS FOLLOWING: " << endl;
    int index = 0;

    while (ptr != NULL)
    {
        cout << "ELEMENTS" << index << " : " << ptr->data << endl;
        ptr = ptr->next;
        index++;
    }
}
// **********************************inssertion in linkedlist*************************
// case1:

struct node *insert_at_first_index(struct node *head, int data)
{
     node *ptr = new node;
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
// case2:

struct node *insert_at_middle_index(struct node *head, int index, int data)
{
    node *ptr = new node;
    struct node *p = head;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// case3:

struct node *insert_at_last_index(struct node *head, int data)
{
    node *ptr = new node;
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// case4:

struct node *insert_at_given_index(struct node *head, struct node *prevnode, int data)
{
    node *ptr = new node;
    if (prevnode == NULL)
    {
        cout << "Previous node cannot be null" << endl;
        return head;
    }

    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}

// *********************************************deletion in linked list*********************************************
// case1:
struct node *deletion_at_first_index(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    delete (ptr);
    return head;
}

// case 2:
struct node *deletion_at_middle_index(struct node *head, int index)
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

// case 3:
struct node *deletion_at_last_index(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    delete q;
    return head;
}
// case4 :

struct node *deletion_at_given_index(struct node *head, int target)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != target && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == target)
    {

        p->next = q->next;
        delete (q);
        return head;
    }
}  
    int main()
    {
        node *head = new node;
        node *second = new node;
        node *third = new node;
        node *fourth = new node;
        node *five = new node;

        head->data = 10;
        head->next = second;

        second->data = 20;
        second->next = third;

        third->data = 30;
        third->next = fourth;

        fourth->data = 40;
        fourth->next = five;

        five->data = 60;
        five->next = NULL;

        traversal(head);
        cout << endl;
        // *******************************************************************insertion**************************************************
        // cout << "After insertion at first" << endl;
        // head = insert_at_first_index(head, 5);
        // traversal(head);

        // cout << endl;

        // cout << "AFter inserting at middle:" << endl;
        // head = insert_at_middle_index(head, 2, 15);
        // traversal(head);

        // cout << endl;

        // cout << "AFter inserting at last index:" << endl;
        // head = insert_at_last_index(head, 50);
        // traversal(head);

        // cout << endl;

        // cout << "AFter inserting at given index:" << endl;
        // head = insert_at_given_index(head,third,35);
        // traversal(head);

        // ***************************************************************deletion*******************************************

        // cout << "After deleting the first index " << endl;
        // head = deletion_at_first_index(head);
        // traversal(head);

        cout << endl;

        // cout << "After deleting the middle index " << endl;
        // head = deletion_at_middle_index(head, 2);
        // traversal(head);

        cout << endl;

        // cout << "After deleting the last index " << endl;
        // head = deletion_at_last_index(head);
        // traversal(head);

        cout << endl;

        cout << "After deleting at given index " << endl;
        head = deletion_at_given_index(head, 20);
        traversal(head);

        return 0;
    }