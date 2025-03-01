#include <iostream>
using namespace std;

// void printstar(int n)
// {
// for (int i = 0; i < n; i++)
// {
//     for (int j = 0; j <= i; j++)
//     {
//         cout<<" * ";
//     }
//     cout<<endl;
// }
void printstar(int n)
{
for (int i = n; i >0; i--)
{
    for (int j = 0; j < i; j++)
    {
        cout<<" * ";
    }
    cout<<endl;
}


}
int main()
{
    int n;
    cout << "Enter the number of rows ";
    cin >> n;

    printstar(n);
    return 0;
}
