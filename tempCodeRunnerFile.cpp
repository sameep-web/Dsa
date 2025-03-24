#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *arr;
};

int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {

        return 1;
    }
    else
    {

        return 0;
    }
}
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {

        return 1;
    }
    else
    {

        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        cout << "stack is full" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        cout << "Stack is already empty " << endl;
    }
    else
    {
        int value = ptr->arr [ptr->top];
        ptr->top--;
        return value;
    }
}
int main()
{
    struct stack *spointer = new stack;
    spointer->size = 5;
    spointer->top = -1;
    spointer->arr = new int[spointer->size];
    cout << "Stack is " << isfull(spointer) << endl;
    cout << "Stack is " << isempty(spointer) << endl;

    cout << endl;

    push(spointer, 10);
    push(spointer, 20);
    push(spointer, 30);
    push(spointer, 40);
    push(spointer, 50);
    cout << "After pushing the element in stack : " << isfull(spointer) << " "<<isempty(spointer);

    cout<<endl;
    cout<<"Poped the element "<<pop(spointer)<<" From the stack "<<endl;
    return 0; 
}