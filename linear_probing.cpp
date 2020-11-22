#include<iostream>
using namespace std;


int get_idx(int key)
{
    return key%10;
}

int probe(int H[],int key)    // Find empty location in the hashtable
{
    int index = get_idx(key);
    int i = 0;
    while(H[index+i] != 0)
    {
        i++;
    }
    return (index+i)%10;
}

void insert(int a[], int key)
{
    int index = get_idx(key);
    if(a[index] != 0)
    {
        index = probe(a, key);
    }
    a[index] = key;
}

int search(int a[],int key)
{
    int i=0;
    int index = get_idx(key);
    while(a[(index+i)%10] != key)
    {
        i++;
        if(a[(index+i)%10] == '\0')
        {
                return -1;

        }
    }

    if(a[(index+i)%10] == key)
    {
        return (index+i)%10;
    }
}


int main()
{
    int a[10] = {0};
    insert(a, 2);
    insert(a, 20);
    insert(a, 28);
    insert(a, 9);
    insert(a, 123);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
    cout<<search(a, 123);
    cout<<endl;
    cout<<search(a, 25);
    cout<<endl; 

}