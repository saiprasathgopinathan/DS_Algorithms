#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x)
{
    Node *t = new Node;
    if(t == NULL)
    {
        cout<<"Queue is full";
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        {
            front =rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

void dequeue()
{
    int x = -1;
    Node *t = new Node;
    if(front == NULL)
    {
        cout<<"Queue is empty";
    }
    else
    {
        t = front;
        x = t->data;
        front = front->next;
        delete(t);
    }
}

void Disp(Node *p)
{
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Disp(front);
}