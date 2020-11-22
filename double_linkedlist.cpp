#include<iostream>
using namespace std;

class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
};
Node *first = NULL;

void create(int a[], int n)
{
    Node *t, *last;
    first = new Node();
    first->data = a[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    for(int i=1;i<n;i++)
    {
        t = new Node();
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Disp(Node *p)
{
    cout<<endl;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int count(Node *p)
{
    int i = 0;
    while(p != NULL)
    {
        i +=1;
        p = p->next;
    }
    return i;
}

void insert(Node *p, int pos, int x)
{
    Node *t;
    if(pos < 0 || pos > count(p))
    {
        cout<<"Position is invalid"<<endl;
        return;
    }
    if(pos == 1)
    {
        if(first == NULL)
        {
            first = p;
        }
        else
        {
            t = new Node();
            t->data = x;
            t->prev = NULL;
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p = p->next;
        }
        t = new Node();
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next != NULL)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

void del(Node *p, int pos)
{
    int x;
    if(pos < 0 || pos > count(p))
    {
        cout<<"Invalid position"<<endl;
    }
    if(pos == 1)
    {
        first = first->next;
        if(first != NULL)
        {
            first->prev = NULL;
        }
        x = first->data;
        delete(first);
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next != NULL)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        delete(p);
    }
}

void reverse(Node *p)
{
    Node *temp;
    p = first;
    while(p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    create(a, 5);
    Disp(first);
    cout<<"The total number of elements= "<<count(first)<<endl;
    insert(first, 5, 20);
    Disp(first);
    del(first, 1);
    Disp(first);
    reverse(first);
    Disp(first);
}

