#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    int index = 0;
    cout << "ELEMENTS OF LINKED LIST ARE AS FOLLOWING : " << endl;
    while (ptr != NULL)
    {
        cout << "ELEMENTS " << index << " : " << ptr->data << endl;
        ptr = ptr->next;
        index++;
    }
}

struct node *insertatfirst(struct node *head, int data)
{
    node *ptr = new node;
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node *insertatindex(struct node *head, int data, int index)
{
    node *ptr = new node;
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *insertatend(struct node *head, int data)
{
    node *ptr = new node;
    ptr->data = data;
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *insertafterindex(struct node *prevnode, struct node *head, int data)
{
    if (prevnode == NULL)
    {
        cout<<"PRevious node cannot be null"<<endl;
        return head;
    }
    
    node *ptr = new node;
    ptr->data = data;

    ptr->next = prevnode->next;
    prevnode->next = ptr;

    return head;
    
}
int main()
{
    node *head = new node();
    node *second = new node();
    node *third = new node();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    traversal(head);

    cout << endl;

    cout << "INSERT AT BEGGINGING: " << endl;
    // insertatfirst(head, 54);
    head = insertatfirst(head, 54);
    traversal(head);
    cout << endl;

    cout << "INSERT AT INDEX: " << endl;
    // insertatindex(head, 56,1);
    head = insertatindex(head, 56, 1);
    traversal(head);
    cout << endl;

    cout << "INSERT AT THE END : " << endl;

    head = insertatend(head, 12);
    traversal(head);
    cout << endl;

    cout << "INSERT AFTER A NODE: " << endl;
    head = insertafterindex(second, head, 35);
    traversal(head);

    return 0;
}