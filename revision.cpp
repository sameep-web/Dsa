#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *insertatfirst(struct node *head, int data)
{

    node *ptr = new node;
    ptr->data = data;
    ptr->next = head;
    return head;
}

struct node *insertatmiddle(struct node *head, int index, int data)
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
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct node *insertafterindex(struct node *prevnode, struct node *head, int data)
{
    if (prevnode == NULL)
    {
        cout << "Prev node cannot be null" << endl;
        return head;
    }
    node *ptr = new node;
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}
void traversal(struct node *ptr)
{
    int index = 0;
    while (ptr != NULL)
    {
        cout << "ELEMENTS " << index << " : " << ptr->data << endl;
        ptr = ptr->next;
        index++;
    }
}
int main()
{
    cout<<"THE ELEMENTS OF LINKED LIST ARE AS FOLLOWING : "<<endl;
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

    fourth-> data = 40;
    fourth-> next = NULL;

    traversal(head);

    cout << endl;

    cout<<"Insert at first: "<<endl;
    head = insertatfirst(head , 100);
    traversal(head);
    cout<<endl;

    cout<<"Insert at middle: "<<endl;
    head = insertatmiddle(head , 2 , 200);
    traversal(head);
    cout<<endl;

    cout<<"Insert at end: "<<endl;
    head = insertatend(head , 500);
    traversal(head);
    cout<<endl;

    cout<<"Insert between element: "<<endl;
    head = insertafterindex(second,head,400);
    traversal(head);
    cout<<endl;

    return 0;
}