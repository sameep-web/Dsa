#include <iostream>
using namespace std;

struct Myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct Myarray *a, int tsize, int usize)
{
    // (*a).total_size = tsize;
    // (*a).used_size = usize;
    // (*a).ptr = (int *)malloc(tsize * sizeof(int));

    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}

void show(struct Myarray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
void set(struct Myarray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        (a->ptr[i]) = n;
    }
}

int main()

{
    struct Myarray marks;
    createarray(&marks, 10, 2);
    cout<<"WE are running set now "<<endl;
    set(&marks);
    cout<<"We are running show now "<<endl;
    show(&marks);
    return 0;
}
