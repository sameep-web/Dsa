#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

node *create_linklist(node *head, int data)
{
    node *ptr = new node;
    ptr->data = data;
    ptr->next = nullptr;

    if (head == nullptr)
    {
        return ptr;
    }

    node *q = head;
    while (q->next != nullptr)
    {
        q = q->next;
    }

    q->next = ptr;
    return head;
}
void traversal(struct node *ptr)
{
    cout << "ELEMENTS OF LINK LIST:- " << endl;
    int index = 0;

    while (ptr != nullptr)
    {
        cout << "ELEMENT " << index << " : " << ptr->data << endl;
        ptr = ptr->next;
        index++;
    }
}

int main()
{
    node *head = nullptr;

    head = create_linklist(head, 10);
    head = create_linklist(head, 20);
    head = create_linklist(head, 30);
    head = create_linklist(head, 40);
    head = create_linklist(head, 50);
    head = create_linklist(head, 60);

    traversal(head);
    return 0;
}