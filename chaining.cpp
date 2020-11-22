#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class Hashtable
{
    public:
    Node **HT;
    Hashtable()
    {
        HT = new Node*[10];
        for(int i=0;i<10;i++)
        {
            HT[i] = NULL;
        }
    }

    int get_idx(int key)
    {
        return key%10;
    }
    
    void insert(int key)                // it is done only once
    {
        Node *t = new Node;
        t->data = key;
        t->next = NULL;
        int idx = get_idx(key);
        if(HT[idx] == NULL)
        {
            HT[idx] = t;
        }
        else
        {
            Node *p = HT[idx];
            Node *q = HT[idx];
            while(p && p->data < key)
            {
                q = p;
                p = p->next;
            }
            if(q == HT[idx])
            {
                t->next = HT[idx];
                HT[idx] = t;
            }
            else
            {
                t->next = q->next;
                q->next = t;
            }
        }
    }

    int search(int key)
    {
        int idx = get_idx(key);
        Node *p = HT[idx];
        while(p)
        {
            if(p->data == key)
            {
                return idx;
            }
            p = p->next;
        }
        if(p == NULL)
        {
            return -1;
        }
    }

    ~Hashtable()
    {
        for(int i=0;i<10;i++)
        {
            Node *p = HT[i];
            while(HT[i])
            {
                HT[i] = HT[i]->next;
                delete p;
                p = HT[i];
            }
        }
        delete [] HT;
    }
};

int main()
{
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    Hashtable H;
    for(int i=0;i<10;i++)
    {
        H.insert(A[i]);
    }
    int k = H.search(16);
    cout<<k<<endl;
    if(k != -1)
    {
        cout<<"Successful"<<endl;
    }
    else
    {
        cout<<"Unsuccessful"<<endl;
    }
    
}