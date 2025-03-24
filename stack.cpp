#include <iostream>
using namespace std;

struct stack {
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr) {
    return (ptr->top == -1);
}

int isfull(struct stack *ptr) {
    return (ptr->top == ptr->size - 1);
}

int main() {
    struct stack *s = new stack;
    s->size = 80;
    s->top = -1;
    s->arr = new int[s->size];

    // Pushing an element manually
    s->arr[0] = 4;
    s->top++;

    // Check if stack is empty
    if (isempty(s)) {
        cout << "The stack is empty" << endl;
    } else {
        cout << "The stack is not empty" << endl;
    }

    return 0;
}
