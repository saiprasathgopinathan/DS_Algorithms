#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class stack
{
    public:
    Node *top;
    stack()
    {
        top = NULL;
    }

    void push(char *s)
    {
        Node *t = new Node;
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

    void pop()
    {
        int x;
        if(top == NULL)
        {
            cout<<"Stack UnderFlow";
        }
        else
        {
            Node *p = top;
            x = p->data;
            top = top->next;
            delete p;
        }
    }

    void Disp(Node *p)
    {
        p = top;
        while(while p!= NULL)
        {
            cout<<p->data;
            p = p->next;
        }
    }
};

int is_balanced(stack *stk,char *exp)
{
    for(int i=0;exp[i] != '\0'; i++)
    {
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            stk->push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if(stk->top == NULL)
            {
                return 0;
            }
            else
            {
                char temp = stk.top();
                if(temp == '{' && exp[i] == '}')
                {
                    stk->pop();
                }
                else if(temp == '[' && exp[i] == ']')
                {
                    stk->pop();
                }
                else if(temp == '(' && exp[i] == ')')
                {
                    stk->pop();
                }

            }
        }
        if(stk->top == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    stack s;
    char E[] = "((a+b)*(c-d))";
    cout<<is_balanced(&s, E);
}
