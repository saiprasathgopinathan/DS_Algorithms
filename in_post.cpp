#include<iostream>
#include <string.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

Node *top=NULL;

void push(char x)
{
    Node *t = new Node;
    if(t == NULL)
    {
        cout<<"Stack is OverFlow";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    char x;
    if(top == NULL)
    {
        cout<<"Stack is UnderFlow";
    }
    else
    {
        Node *t = top;
        x = t->data;
        top = top->next;
        delete t;
    }
    return x;
}

int is_operand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;

    return 1;
}

int pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
        
    return 0;
}

char *in_post(char *infix)
{
    int i=0,j=0;
    char *  postfix = new char[strlen(infix)+2];
    while(infix[i] != '\0')
    {
        if(is_operand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if(pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while(top != NULL)
        postfix[j++] = pop();

    postfix[j] = '\0';
    
    return postfix;
}

int main()
{
    // char *x = "a+b*c";
    char *x = "A+B*(C+D)/F+D*E";
    push('#');
    cout<<in_post(x)<<endl;
}