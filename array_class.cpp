#include<iostream>
using namespace std;

class Array
{
    private:
    int *A;
    int size;
    int length;

    public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    void insert(int index, int x)
    {
        if(index >= 0 && index <= length)
        {
            for(int i=length-1; i>=index; i--)
            {
                A[i] = A[i+1];
            }
            A[index] = x;
            length++;
        }
    }
    void disp()
    {
        for(int i=0;i<length;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    void del(int index)
    {
        if(index >= 0 && index<=length)
        {
            for(int i=index; i<length-1; i++)
            {
                A[i] = A[i+1];
            }
            length--;
        }
    }
};

int main()
{
    Array arr1;
    arr1.insert(0, 10);
    arr1.insert(1, 11);
    arr1.insert(2, 12);
    arr1.insert(3, 13);
    arr1.disp();
    arr1.del(1);
    arr1.disp();
}