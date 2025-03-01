#include <iostream>
using namespace std;

int sum(Node node)
{
    if (node == NULL)
        ;
    {
        return 0;
    }
    return sum(node.left) + node.value + sum(node.right);
}
int main()
{
    sum(4);

    return 0;
}
