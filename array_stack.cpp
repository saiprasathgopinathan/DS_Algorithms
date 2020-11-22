#include<iostream>
using namespace std;

class stack
{
    public:
    int top;
    int size;
    int *S;
};

void create(stack *st)
{
    cout<<"Enter size of array: ";
    cin>>st->size;
    st->top = -1;
    st->S = new int[st->size];
}

void Disp(stack *st)
{
    for(int i=0;i<st->size;i++)
    {
        cout<<st->S[i]<<" ";
    }
}

void push(stack *st, int x)
{
    if(st->top == st->size - 1)
    {
        cout<<"Stack OverFlow"<<endl;
    }
    else
    {
        st->top += 1;
        st->S[st->top] = x;
    }
}

int pop(stack *st)
{
    int x = -1;
    if(st->top < 0)
    {
        cout<<"Stack UnderFlow"<<endl;
    }
    else
    {
        x = st->S[st->top];
        st->top -= 1;
        cout<<"Popped= "<<x<<endl;
    }
    return x;
}

int peek(stack *st, int pos)
{   
    int x = -1;
    if(st->top - pos +1 < 0)
    {
        cout<<"Invalid Index"<<endl;
    }
    else
    {
        x = st->S[st->top - pos +1];

    }
    return x;
}


int main()
{
    stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 50);
    Disp(&st);
    // cout<<endl;
    // pop(&st);
    // pop(&st);
    // pop(&st);
    // pop(&st);
    cout<<endl;
    // Disp(&st);
    cout<<peek(&st, 2);
}
