#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
Node *top = NULL;

void push(int x)
{
    Node *t=new Node;
    if(t == NULL)
    {
        cout<<"Stack OverFlow"<<endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int x;
    Node *t;
    if(top == NULL)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        t = top;
        x = t->data;
        top = t->next;
        delete t;
    }
    return x;
}

void Disp()
{
    Node *p = top;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}



int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    Disp();
    cout<<pop();
    cout<<endl;
    Disp();

}
