#include<iostream>
using namespace std;

void swap(int *i, int *j)
{
    int t = *i;
    *i = *j;
    *j = t;
}

void bubble(int a[], int n)
{
    int flag = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j = 0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}

void insertion(int a[], int n)
{
    int x;
    for(int i=1;i<n;i++)
    {
        int j = i-1; // i = element after j
        x = a[i];
        while(j>=0 && a[j] > x)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void selection(int a[],int n)
{
    int i,j,k;
    for(int i=0;i<n-1;i++)
    {
        for(j=k=i; j<n;j++)
        {
            if(a[k] > a[j])
            {
                k = j;
            }
        }
        swap(&a[k], &a[i]);
    }
}

int partition(int a[], int l, int h)
{
    int i = l;
    int j = h;
    int pivot = a[l];
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)         // this will be executed only when the array is not sorted
        {
            swap(&a[i], &a[j]);
        }
    } while (i<j);
    swap(&a[j], &a[l]);
    return j;
}

void quick_sort(int a[], int l, int h)
{
    int j;
    if(l < h)
    {
        j = partition(a, l, h);
        quick_sort(a, l, j);
        quick_sort(a, j+1, h);
    }
}

int main()
{
    int a[] = {5,8,3,1,4,2,9,0};
    int n = sizeof(a)/sizeof(a[0]);
    // bubble(a, n);
    // insertion(a, n);
    quick_sort(a, 0, n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}