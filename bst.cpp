#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *lchild;
    Node *rchild;
};

Node *root = NULL;
void iter_insert(int key)
{
    Node *r = NULL, *p;  // p =for creating new Node, r = following pointer
    Node *t = root;
    if(root == NULL)
    {
        p = new Node();
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while(t != NULL)
    {
        r = t;
        if(key > t->data)
        {
            t = t->rchild;
        }
        else if(key < t->data)
        {
            t = t->lchild;
        }
        else     // stop adding duplicate elements
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key > r->data)
    {
        r->rchild = p;
    }
    else
    {
        r->lchild = p;
    }
}

Node *search(int key)
{
    Node *t = root;
    if(t->data == key)
    {
        return t;
    }
    else if(t->data < key)
    {
        t = t->rchild;
    }
    else if(t->data > key)
    {
        t = t->lchild;
    }
    return NULL;
}

void inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

Node * insert(Node *p, int key)   // first create a root node then start inserting
{
    Node *t = NULL;
    if(p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(p->data > key)
    {
        p->lchild = insert(p->lchild, key);
    }
    else if(p->data < key)
    {
        p->rchild = insert(p->rchild, key);
    }
    return p;
}

int Height(Node *p)
{
    int x, y;
    if(p == NULL)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    if(x>1)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }
}

Node *in_pre(Node *p)
{
    while(p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

Node *in_suc(Node *p)
{
    while(p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}


Node * del(Node *p, int key)
{
    if(p == NULL)
    {
        return NULL;
    }

    Node * q = NULL;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if(p->data > key)
    {
        p->lchild = del(p->lchild, key);
    }
    else if(p->data < key)
    {
        p->rchild = del(p->rchild, key);
    }
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = in_pre(p->lchild);
            p->data = q->data;
            p->lchild = del(p->lchild, q->data);
        }
        else
        {
            q = in_suc(p->rchild);
            p->data = q->data;
            p->rchild = del(p->rchild, q->data);

        }
    }
    return p;
}

int main()
{
    Node *temp;
    root = insert(root, 50);
    insert(root, 10);
    insert(root, 40);
    insert(root, 20);
    insert(root, 30);

    temp = search(201);
    if(temp != NULL)
    {
        cout<<"Found"<<endl;
    }
    inorder(root);
    cout<<"Deleting: "<<endl;
    del(root, 30);
    inorder(root);
    cout<<endl;
    cout<<"Height= "<<Height(root)<<endl;
}