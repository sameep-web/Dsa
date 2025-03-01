#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
void deletion(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int linearsearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[100] = {2, 45, 32, 11, 67};
    int size = 5, index = 0;
    cout << "Before deletion: ";
    display(arr, size);
    cout << endl;

    int element = 2;
    if (index >= 0 && index < size)
    {

        deletion(arr, size, index);
        size -= 1;

        cout << "ARRAY AFTER DELETION: ";
        display(arr, size);
        cout<<endl;
    }
    else
    {
        cout << "Deletion is failed! " << endl;
    }

    int target;
    cout<<"Enter the element you want to search : "<<endl;
    cin>>target;

    int result = linearsearch(arr, size, target);
    if (result != -1)
    {
        cout << "The element in array is placed at an index " << result;
    }
    else
    {
        cout << "The element was not found in this array " << endl;
    }

    return 0;
}
