#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

node *createlinkedlist(int arr[], int size)
{
    if (size == 0)
        return nullptr;
    node *head = new node(arr[0]);
    node *temp = head;
    for (int i = 1; i < size; i++)
    {
        temp->next = new node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void traverse(node *head)
{
    cout << "LINKED LIST ELEMENTS: " << endl;
    node *temp = head;
    int index = 0;

    while (temp != nullptr)
    {
        cout << "ELEMENT " << index << " : " << temp->data << endl;
        temp = temp->next;
        index++;
    }
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    node *head = createlinkedlist(arr, size);

    traverse(head);
    return 0;
}