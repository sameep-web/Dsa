#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int value)
{
    if (isfull(ptr))
    {
        cout << "Stack is fulled no more pushing " << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        cout << "Stack is empty no more poping " << endl;
    }
    else
    {

        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int index = ptr->top - (i - 1);
    if (index < 0)
    {
        cout << "Invalid position" << endl;
        return -1;
    }
    else
    {
        return ptr->arr[index];
    }
}

int top(struct stack * ptr){
    return ptr->arr[ptr->top];
}

int bottom(struct stack * ptr){
    return ptr->arr[0];
}

int main()
{
    struct stack *spointer = new stack;
    spointer->size = 5;
    spointer->top = -1;
    spointer->arr = new int[spointer->size];
    cout << "Stack is implemented" << endl;

    push(spointer, 10);
    push(spointer, 20);
    push(spointer, 30);
    push(spointer, 40);
    push(spointer , 50);
    

    cout << "The stack after pushing " << isfull(spointer);

    cout << endl;
    cout << "poped : " << pop(spointer) << " FROM THE STACK " << endl;

    cout<<"The topmost element of stack is "<<top(spointer)<<endl;
    cout<<"The bottom most element of stack is "<<bottom(spointer)<<endl;
    for (int j = 1; j <= spointer->top + 1; j++)
    {
        cout<<"The value at position "<< j<< " IS "<<peek(spointer , j)<<endl;
    }
    
    
    return 0;
}