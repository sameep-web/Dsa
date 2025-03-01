#include <iostream>
using namespace std;

int recursivelinearsearch(int arr[], int n, int target, int index = 0)
{
    if (index >= n)
        return -1;
    if (arr[index] == target)
        return index;
    return recursivelinearsearch(arr, n, target, index + 1);
}
int main()
{
    int arr[] = {5, 8, 12, 1, 18, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 18;

    int result = recursivelinearsearch(arr, n, target);
    (result != -1) ? cout << "Element was found at index " << result
                   : cout << "Element was not found ";
    return 0;
}
