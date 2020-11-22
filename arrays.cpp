#include<iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void disp(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(struct Array *arr)                // Time complexity is less
{
    for(int i=0, j=arr->length-1; i<j ;i++, j--)
    {
        swap(arr->A[i], arr->A[j]);
    }
}

void rev_1(struct Array *arr)
{
    int b[arr->length];
    for(int i=arr->length-1, j=0; i>=0;i--, j++)
    {
        b[j] = arr->A[i];
    }
    for(int i=0;i<arr->length;i++)
    {
        arr->A[i] = b[i];
    }
}

void insert(struct Array *arr, int x) // here the array is sorted and the number is inserted still sort is maintained
{
    int i = arr->length-1;

    if(arr->length > arr->size)
    {
        return;
    }
    while(arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

void split(struct Array *arr)   // arrange +ve and -ve on each side
{
    int i =0;
    int j = arr->length -1;
    while(i<j)
    {
        while(arr->A[i] < 0) i++;
        while(arr->A[j] > 0) j--;
        if(i<j)
        {
            swap(arr->A[j], arr->A[i]);
        }
    }
}

void split_for(struct Array *arr)  // It doesnot work because in a single iteration i increments and j decrements hence it reverses the array
{
    for(int i=0, j=arr->length-1 ;i<j; i++, j--)
    {
        if(arr->A[j] < 0 || arr->A[i] > 0)
        {
            swap(arr->A[i], arr->A[j]);
        }
    }
}

struct Array *merge(struct Array *arr1, struct Array *arr2)
{
    int n = arr1->length + arr2->length;
    struct Array *arr3 = new struct Array[n];
    int i = 0, j = 0, k = 0;
    int n1 = arr1->length;
    int n2 = arr2->length;
    while(i<n1 && j<n2)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr1->A[j++];
        }
    }
    for(; i<n1;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(; j<n1;j++)
    {
        arr3->A[k++] = arr2->A[j];        
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr3->length;

    return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int n = arr1->length + arr2->length;
    struct Array *arr3 = new struct Array[n];
    int i = 0, j = 0, k = 0;
    int n1 = arr1->length;
    int n2 = arr2->length;
    // cout<<n1<<' '<<n2<<endl;
    while(i<n1 && j<n2)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            // cout<<"i<j"<<endl;
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            // cout<<"i>j"<<endl;
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            // cout<<"i=j"<<endl;
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(; i<n1;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(; j<n1;j++)
    {
        arr3->A[k++] = arr2->A[j];        
    }
    // arr3->length = arr1->length + arr2->length;
    arr3->length = k;
    arr3->size = arr3->length;

    return arr3;
}

struct Array *Instersection(struct Array *arr1, struct Array *arr2)  // since only common elements are being taken 
{
    int n = arr1->length + arr2->length;
    struct Array *arr3 = new struct Array[n];
    int i = 0, j = 0, k = 0;
    int n1 = arr1->length;
    int n2 = arr2->length;
    // cout<<n1<<' '<<n2<<endl;
    while(i<n1 && j<n2)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            // cout<<"i<j"<<endl;
            // arr3->A[k++] = arr1->A[i++];
            i++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            // cout<<"i>j"<<endl;
            // arr3->A[k++] = arr2->A[j++];
            j++;
        }
        else
        {
            // cout<<"i=j"<<endl;
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    // arr3->length = arr1->length + arr2->length;
    arr3->length = k;
    arr3->size = arr3->length;

    return arr3;
}

struct Array *Difference(struct Array *arr1, struct Array *arr2)  // Since it picks elements which are not common in arrays only one array condition is executed
{
    int n = arr1->length + arr2->length;
    struct Array *arr3 = new struct Array[n];
    int i = 0, j = 0, k = 0;
    int n1 = arr1->length;
    int n2 = arr2->length;
    // cout<<n1<<' '<<n2<<endl;
    while(i<n1 && j<n2)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            // cout<<"i<j"<<endl;
            arr3->A[k++] = arr1->A[i++];
            i++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            // cout<<"i>j"<<endl;
            // arr3->A[k++] = arr2->A[j++];
            j++;
        }
        else
        {
            // cout<<"i=j"<<endl;
            i++;
            j++;
        }
    }
    // arr3->length = arr1->length + arr2->length;
    arr3->length = k;
    arr3->size = arr3->length;

    return arr3;
}

int main()
{
    struct Array a1={{1, 2, 3, 4, 5}, 20, 5};
    struct Array a2={{2, 5, 8, 9, 10}, 20, 5};
    // insert(&a, 0);
    // split_for(&a);
    struct Array *a3;
    // a3 = Difference(&a1, &a2);
    // a3 = merge(&a1, &a2);
    
    // for(int i=0; i<a3->length; i++)
    // {
    //     cout<<a3->A[i]<<" ";
    // }
    int ch;
    do
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Reverse"<<endl;
        cout<<"Enter a choice"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:int x;
            cout<<"Enter an element";
            cin>>x;
            insert(&a1, x);
            break;
            case 2:disp(a1);
            break;
            case 3:reverse(&a1);
            cout<<endl;
            disp(a1);
            break;

        }
    }while(ch<4);

    disp(*a3);
    return 0;
}
