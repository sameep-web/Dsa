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
    return 0;
}
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *ptr, int value)
{
    if (isfull(ptr))
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack * ptr ){

    if (isempty(ptr))
    {
        cout<<"Stack is underflow"<<endl;
return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;

    }
}

int main()
{
    struct stack *spointer = new stack;
    spointer->size = 10;
    spointer->top = -1;
    spointer->arr = new int[spointer->size];
    cout << "Stack has been created successfully" << endl;

    cout << isfull(spointer) << endl;
    cout << isempty(spointer) << endl;
    push(spointer, 56);
    push(spointer, 5);
    push(spointer, 6);
    push(spointer, 34);
    push(spointer, 16);
    

    cout << "After pushing , full : " << isfull(spointer) << endl;
    cout << "After pushing , empty : " << isempty(spointer) << endl;
     cout<<"poped "<<pop(spointer) << " from the stack"<<endl;
    

    return 0;
}