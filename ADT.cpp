#include <iostream>
using namespace std;
class myarray
{
private:
    int total_size;
    int used_size;
    int *ptr;

public:
    myarray(int tsize, int usize)
    {
        total_size = tsize;
        used_size = usize;
        ptr = new int[tsize];
    }

    void setelement()
    {
        int n;
        for (int i = 0; i < used_size; i++)
        {
            cout << "Enter Element " << i + 1 << " : ";
            cin >> n;
            ptr[i] = n;
        }
    }
    void showelemnt() const
    {
        cout << "Array element are: \n";
        for (int i = 0; i < used_size; i++)
        {
            cout << ptr[i] << endl;
        }
    }

    ~myarray()
    {
        delete[] ptr;
        cout << "Memory freed " << endl;
    }
};

int main()
{
    myarray marks(10, 2);
    cout << "WE are running setelement now " << endl;
    marks.setelement();
    cout << "We are running show now " << endl;
    marks.showelemnt();
    cout<<"Destructor is called"<<endl;
    return 0;
}
