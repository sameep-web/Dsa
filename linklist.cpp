#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    { 
        cout <<" element : " << ptr->data<<endl;
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head;
    struct node *Second;
    struct node *Third;
    struct node *Fourth;

    // allocate memory for nodes in linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    Second = (struct node *)malloc(sizeof(struct node));
    Third = (struct node *)malloc(sizeof(struct node));
    Fourth = (struct node *)malloc(sizeof(struct node));

    // link first and second nodes
    head->data = 71;
    head->next = Second;

    // link second and third nodes
    Second->data = 88;
    Second->next = Third;

    // link second and third node
    Third->data = 91;
    Third->next = Fourth;

//link third and fouth node

Fourth -> data = 212;
Fourth -> next = NULL;


    traversal(head);
    return 0;
}
