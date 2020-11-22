#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node *next;
};

Node *top = NULL;

// void push(Node *st,char s)
void push(char s)
{
    Node *t=new Node();
    if(t == NULL)
    {
        cout<<"Stack OverFlow";
    }
    else
    {
        t->data = s;
        t->next = top;
        top = t;
    }
}

char pop()
{
    Node *t;
    char x = -1;
    if(top == NULL)
    {
        cout<<"Stack UnderFlow";
    }
    else
    {
        t = top;
        top = top->next;
        delete t;
    }
    return x;
}

int isEmpty() 
{
    return top ? 0 : 1;
}


int is_balanced(char *exp)
{
    // int in[];
    // int out[];
    int temp;
    int x;
    for(int i=0;exp[i] != '\0';i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            // temp = exp[i];
            push(exp[i]);
        }
        else 
        {
            if(top == NULL)
            {
                return 0;
            }
            else if(exp[i] == char(41))
            {
                
                // out.insert(exp[i]);
                pop();
            }
            else if(exp[i] == char(93))
            {
                // out.insert(exp[i]);
                pop();
            }
            else if(exp[i] == char(125))
            {
                // out.insert(exp[i]);
                pop();
            }
        }
    }
    if(isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_bal(char *exp)
{
    for(int i=0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            push(exp[i]);
            cout<<top->data<<" ";
        }
        else
        {
            if(top->data == '{' && exp[i] == '}')
            {
                
                cout<<pop();
            }

            if(top->data == '(' && exp[i] == ')')
            {
                cout<<pop();
            }
            
            if(top->data == '[' && exp[i] == ']')
            {
                cout<<pop();
            }
        }
    }
    if(isEmpty())
    {
        top = NULL;
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    char e[] = "{a+b)";
    cout<<is_bal(e);
    cout<<endl;
}