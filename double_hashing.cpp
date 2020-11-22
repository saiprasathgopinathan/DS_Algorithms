#include<iostream>
using namespace std;

int Hash(int key)
{
    return key%10;
}

int prime_hash(int key)
{
    return 7 - key%7;
}

int double_hash(int a[], int key)
{
    int idx = Hash(key);
    int i =0;
    while(a[(Hash(key) + i*prime_hash(key))%10] != 0)
    {
        i++;
    }
    return (Hash(key) + i*prime_hash(key))%10;
}

void insert(int a[], int key)
{
    int idx = Hash(key);
    while(a[idx] != 0)
    {
        idx = double_hash(a, key);
    }
    a[idx] = key;
}

int search(int a[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while(a[(Hash(key) + i*prime_hash(key))%10] != key)
    {
        i++;
        if(a[(Hash(key) + i*prime_hash(key))%10] == 0)
        {
            return -1;
        }
    }
    return (Hash(key) + i*prime_hash(key))%10;
}

int main()
{
    int a[10] = {0};
    insert(a, 20);
    insert(a, 21);
    insert(a, 22);
    
    insert(a, 19);
    insert(a, 2);

    cout<<search(a, 2)<<endl;
    cout<<search(a, 20)<<endl;
    cout<<search(a, 12)<<endl;

}