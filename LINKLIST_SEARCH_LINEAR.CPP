#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

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
bool linearsearch(struct node *head, int target)
{
    int index = 0;
    while (head != nullptr)
    {
        if (head->data == target)
        {
            cout << "ELEMENT " << target << " IS FOUND AT " << index << endl;
            return true;
        }
        head = head->next;
        index++;
    }

    cout << "ELEMENT WAS NOT FOUND IN LINKED LIST! " << endl;
    return false;
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

    five->data = 50;
    five->next = NULL;

    traversal(head);

    linearsearch(head, 40);
    return 0;
}