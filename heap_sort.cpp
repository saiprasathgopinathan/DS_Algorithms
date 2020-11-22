#include<iostream>
using namespace std;

void insert(int A[], int n)
{
    int temp;
    int i = n;
    temp = A[i];
    while(temp > A[i/2] && i > 1)
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int del(int A[], int n)
{
    int val = A[1];   // largest element
    int i = 1;
    int j = 2*i;
    A[1] = A[n];   
    A[n] = val;     // largest element stored at the end

    while(j <= n-1)
    {
        if(A[j+1] > A[j] && j < n-1)
        {
            j = j+1;
        }
        else if(A[i] < A[j])
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    return val;
}

void heapify(int a[],int n)
{
    for(int i = (n/2) - 1; i >= 0; i--)
    {
        int j = 2*i+1;
        while(j <= n-1)
        {
            if(a[j+1] > a[j])
            {
                j = j+1;
            }
            else if(a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i = j;
                j = 2*i +1;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int H[]={0,14,15,5,20,30,8,40}; 
    int n = sizeof(H)/sizeof(H[0]);
    // for(int i = 2;i<n;i++)
    // {
    //     insert(H,i);
    // }
    heapify(H, n);

    for(int i=1;i<n;i++)
    {
        cout<<H[i]<<" ";
    }

    // cout<<endl;
    for(int i = n-1;i>1;i--)
    {
        del(H,i);
    }
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<H[i]<<" ";
    }
}