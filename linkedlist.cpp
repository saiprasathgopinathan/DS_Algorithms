#include<iostream>
#include <limits>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
Node *first, *third, *second;

void Disp(Node *p)
{
    if(p != NULL)
    {
        cout<<p->data<<" ";
        Disp(p->next);
    }
}

int count_elem(Node *p)
{
    int count = 0;
    while(p != '\0')
    {
        count += 1;
        p = p->next;
    } 
    return count;
}

int sum(Node *p)
{
    int s = 0;
    while(p)
    {
        s+= p->data;
        p = p->next;
    }
    return s;
}

int max_ele(Node *p)
{
    int max = -100;
    while(p != NULL)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}


Node *linear_search(Node *p, int key)
{
    while(p != NULL)
    {
        if(key == p->data)
        {
            cout<<"yes key is found "<<p->data;
            return p;
        }
        p= p->next;
    }
    return NULL;
}

Node* linear_move_first(Node* p, int key)
{
    Node *q = NULL;
    while(p != NULL)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            cout<<"Key found ";
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

Node *insert(Node *p, int pos, int key)
{
    Node *t;
    if(pos == 0)
    {
        t = new Node();
        t->data = key;
        t->next = first;
        first = t;
    }
    else if(pos > 0)
    {
        cout<<endl;
        for(int i=0;i<pos-1 && p;i++)
        {
            cout<<"i= "<<i<<endl;
            p = p->next;
        }
        if(p)
        {
            t = new Node();
            t->next = p->next;
            t->data = key;
            p->next = t;
        }
    }
    return p;
}

Node *append(int x)
{
    Node* last;
    Node *t = new Node();
    t->data = x;
    t->next = NULL;
    if(first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
    return last;
}

void sorted_insert(Node *p, int x)
{
    Node *t, *q = NULL;
    t = new Node();
    t->data = x;
    t->next = NULL;
    if(first == NULL)
    {
        first = t;
    }
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void delete_element(Node *p, int pos)
{
    int x;
    Node *q;
    if(pos == 0)
    {
        p = first;
        x = first->data;
        first = first->next;
        delete p;
    }
    else
    {
        q= NULL;
        for(int i=0;i<pos-1;i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
}

void remove_duplicate(Node *p)
{
    p = first;
    Node *q = first->next;
    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reverse_elem(Node *p)
{
    p = first;
    int a[count_elem(p)];
    int i;
    while(p != NULL)
    {
        a[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i = i-1;
    while(p != NULL)
    {
        p->data = a[i];
        p = p->next;
        i--;
    }
}

void reverse_links(Node *p)
{
    Node *q=NULL;
    Node *r=NULL;
    p = first;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse_recursion(Node *q, Node *p)
{
    if(p != NULL)
    {
        reverse_recursion(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void merging(Node *p, Node *q)
{
    Node *last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p != NULL && q != NULL)
    {
        if(p->data < q->data)
        {
            third = last = p;
            p = p->next;
            third->next = NULL;
        }
        else
        {
            third = last = q;
            q = q->next;
            third->next = NULL;
        }
    }
    if(p != NULL)last->next = p;
    if(q != NULL)last->next = q;
}


int main()
{
    // int a[] = {4,6,3,2,1,12};
    // int n = sizeof(a)/sizeof(a[0]);
    // Node *head, *t, *last;
    // head = new Node();
    // head->data = a[0];
    // head->next = NULL;
    // last = head;
    // for(int i=1;i<n;i++)
    // {
    //     t = new Node();
    //     t->data = a[i];
    //     t->next = NULL;
    //     last->next = t;
    //     last = t;
    // }
    // Node *p = head;
    // first = head;
    // // while(p != NULL)
    // // {
    // //     cout<<p->data<<" ";
    // //     p = p->next;
    // // }
    // Disp(first);
    // cout<<endl;
    // cout<<"Number of elements= "<<count_elem(p)<<endl;
    // cout<<"Sum of elements= "<<sum(p)<<endl;
    // cout<<"Max element is= "<<max_ele(p)<<endl;
    // // linear_move_first(first, 12);
    // cout<<endl;
    // Disp(first);
    // insert(p, 0, 0);
    // cout<<endl<<"100 is inserted"<<endl;
    // Disp(first);
    // append(10);
    // append(10);
    // append(30);
    // append(40);
    // append(40);
    // append(50);
    cout<<endl<<"Printing insert_last"<<endl;
    Disp(first);
    // cout<<endl;
    // sorted_insert(first, 12);
    // cout<<endl;
    // Disp(first);
    // sorted_insert(first, 2);
    // cout<<endl;
    // Disp(first);
    // cout<<endl;
    // // delete_element(first, 6);
    // cout<<endl;
    // cout<<"After Deleting"<<endl;
    // Disp(first);
    // cout<<endl;
    // remove_duplicate(first);
    // cout<<"After Deleting duplicates"<<endl;
    // Disp(first);
    // cout<<endl;    
    // cout<<"After Reversing"<<endl;
    // reverse_elem(first);
    // Disp(first);
    // cout<<endl;    
    // cout<<"After Reversing"<<endl;
    // reverse_links(first);
    // Disp(first);
    // cout<<endl;    
    // cout<<"After Reversing"<<endl;
    // reverse_recursion(NULL,first);
    // Disp(first);
    // cout<<endl;

    int a[] = {1,2,3,4,5};
    int b[] = {6,7,8,9,10};
    Node *last;
    first->data = a[0];
    first->next = NULL;
    for(int i=1; i<5;i++)
    {
        t = new Node();
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

    cout<<"Merging"<<endl;

    // sorted_insert(first, 1);
    // sorted_insert(first, 2);
    // sorted_insert(first, 3);
    // sorted_insert(first, 4);
    // sorted_insert(first, 5);

    // sorted_insert(second, 11);
    // sorted_insert(second, 12);
    // sorted_insert(second, 13);
    // sorted_insert(second, 14);
    // sorted_insert(second, 15);

    cout<<"First"<<endl;
    Disp(first);
    cout<<endl;
    cout<<"Second"<<endl;
    Disp(second);
    cout<<endl;

    // merging(first, second);
    // Disp(third);
    // cout<<endl;
}
