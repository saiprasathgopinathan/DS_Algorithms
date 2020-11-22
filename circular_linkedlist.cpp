#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
Node *head = NULL;

void create_circular(int a[],int n)
{
    Node *t, *last;
    head = new Node();
    head->data = a[0];
    head->next = head;
    last = head;
    for(int i=1;i<n;i++)
    {
        t = new Node();
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Disp(Node *p)
{
    do
    {
        cout<<p->data<<' ';
        p = p->next;
    }while(p != head);
}

void R_Disp(Node *p)
{
    static int flag = 0;
    if(p != head || flag == 0)
    {
        flag = 1;
        cout<<p->data<<' ';
        R_Disp(p->next);
    }
    flag = 0;
}

int count_elem(Node *p)
{
    int count = 0;
    do
    {
        count += 1;
        p = p->next;
    }while(p != head);
    return count;
}

void insert(Node *p, int pos, int x)
{
    Node *t;
    if(pos == 0)
    {
        t = new Node();
        t->data = x;
        if(head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else if(pos < 0 || pos > count_elem(p))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p = p->next;
        }
        t = new Node();
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

void delete_elem(Node *p, int pos)
{
    int x;
    Node *q;
    if(pos==1)
    {
        while(p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if(head == p)
        {
            delete(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete(head);
            head = p->next;
        }
    }
    else
    {
        for(int i=0;i<pos-2;i++)
        {
            p = p->next;
        }
        q = p->next;
        x = q->data;
        p->next = q->next;
        delete(q);

    }
    cout<<x<<" is the deleted element";
}


int main()
{
    int a[] = {1,2,3,4,5};
    create_circular(a, 5);
    Disp(head);
    cout<<endl;
    R_Disp(head);
    cout<<endl;
    cout<<"Number of elements= "<<count_elem(head)<<endl;
    insert(head,0, 10);
    Disp(head);
    cout<<endl;
    delete_elem(head, 2);
    cout<<endl;
    Disp(head);
    cout<<endl;
}