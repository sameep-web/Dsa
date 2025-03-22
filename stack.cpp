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
    else
    {
        return 0;
    }
}

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
int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = new int[s.size];

    struct stack *s = new stack;
    s->size = 80;
    s->top = -1;
    s->arr = new int[s->size];

    // pushing an element manually
    s->arr[0] =  4;
    s->top++;

    // cheack if stack is empty

    if (isempty(s))
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "The stack is not empty" << endl;
    }
    return 0;
}