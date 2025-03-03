#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};
class linkedlist
{
private:
    Node *head;

public:
    linkedlist() : head(nullptr) {}

    void insert(int data)
    {
        Node *newnode = new Node(data);
        if (!head)
        {
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void traverse()
    {
        Node *temp = head;
        while (temp)
        {
            cout << "ELEMENT: " << temp->data << endl;
            temp = temp->next;
        }
    }

    ~linkedlist()
    {
        Node *temp = head;
        while (temp)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    linkedlist list;
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    list.traverse();
    return 0;
}