#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    int height;
    Node *lchild;
    Node *rchild;
};

Node *root = NULL;

int get_height(Node *p)
{
    int x=0, y=0;
    if(p == NULL)
    {
        return 0;
    }
    if(p != NULL && p->lchild != NULL)
    {
        x = p->lchild->height;
    }

    else if(p != NULL && p->rchild != NULL)
    {
        y = p->rchild->height;
    }

    if(x > y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }
    
}

int balance_factor(Node *p)
{
    int x, y;
    x = get_height(p->lchild);
    y = get_height(p->rchild);
    return x - y;
}

Node *LL(Node *p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
 
    pl->rchild = p;
    p->lchild = plr;
 
    p->height = get_height(p);
    pl->height = get_height(pl);
 
    if (root == p){
        root = pl;
    }
    return pl;
}

Node *RR(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    if(p ==root)
    {
        root = pr;
    }

    return pr;
}

Node *LR(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = get_height(p);
    pl->height = get_height(pl);
    plr->height = get_height(plr);

    if(p == root)
    {
        root = plr;
    }

    return plr;
}

Node *RL(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = get_height(p);
    pr->height = get_height(pr);
    prl->height = get_height(prl);

    if(p == root)
    {
        root = prl;
    }

    return prl;
}


Node *insert(Node *p, int key)
{
    Node *t = NULL;
    if(p==NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    else if(key < p->data)
    {
        p->lchild = insert(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = insert(p->rchild, key);
    }

    p->height = get_height(p);
    // cout<<"Balance factor= "<<balance_factor(p)<<endl;

    if(balance_factor(p) == 2 && balance_factor(p->lchild) == 1)
    {
        return LL(p);
    }
    if(balance_factor(p) == -2 && balance_factor(p->rchild) == -1)
    {
        return RR(p);
    }
    if(balance_factor(p) == 2 && balance_factor(p->lchild) == -1)
    {
        return LR(p);
    }
    if(balance_factor(p) == -2 && balance_factor(p->rchild) == 1)
    {
        return RL(p);
    }

    return p;
}

void inorder(Node *p)
{
    if(p)
    {   
        cout<<p->data<<' ';
        inorder(p->rchild);
        inorder(p->lchild);
    }
}

int main()
{
    root = insert(root, 40);
    insert(root, 55);
    insert(root, 42);
    insert(root, 41);
    insert(root, 46);
    
    inorder(root);
    cout<<endl;
    cout<<"Height = "<<get_height(root);
}