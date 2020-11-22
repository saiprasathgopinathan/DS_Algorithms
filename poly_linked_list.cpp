#include<iostream>
#include<cmath>
using namespace std;

class Node
{
    public:
    int exp;
    int coef;
    Node *next;
};

Node *poly =NULL;

void create()
{
    Node *t, *last = NULL;
    int n;
    cout<<"Enter the number of elements";
    cin>>n;
    cout<<"Enter the coefficients and exponents";
    for(int i=0;i<n;i++)
    {
        t = new Node;
        cin>>t->coef>>t->exp;
        if(poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Disp(Node *p)
{
    while(p != NULL)
    {
        cout<<p->coef<<"*x"<<p->exp<<"+";
        p = p->next;
    }
    cout<<endl;
}

double add(Node *p)
{
    float sum = 0;
    int x;
    cout<<"Enter the value of x";
    cin>>x;
    while(p != NULL)
    {
        sum += p->coef*pow(x, p->exp);
        p = p->next;
    }
    return sum;
}

int main()
{
    create();
    Disp(poly);
    cout<<add(poly);
    cout<<endl;
}