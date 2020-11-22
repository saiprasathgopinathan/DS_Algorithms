#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *lchild;
    Node *rchild;
};

class queue
{
    private:
    int front;
    int rear;
    int size;
    Node **Q;

    public:
    queue(int s)
    {
        front = -1;
        rear = -1;
        size = s;
        Q = new Node*[size];
    }

    void enqueue(Node *x)
    {
        if(rear == size-1)
        {
            cout<<"Queue is full";
        }
        else
        {
            rear += 1;
            Q[rear] = x;
        }
    }

    Node *dequeue()
    {
        Node *x = NULL;
        if(rear == front)
        {
            cout<<"Queue is empty";
        }
        else
        {
            front += 1;
            x = Q[front];
        }
        return x;
    }

    bool is_empty()
    {
        if(front == rear)
        {
            return true;
        }
        return false;
    }
};

class tree
{
    private:
    Node *root;

    public:
    tree()
    {
        root = NULL;
    }

    void create()
    {
        Node *p;
        Node *t;
        queue q(10);
        int x;
        cout<<"Enter root value: ";
        cin>>x;
        root = new Node;
        root->data = x;
        root->lchild = NULL;
        root->rchild = NULL;
        q.enqueue(root);
        while(!q.is_empty())
        {
            p = q.dequeue();
            cout<<"Enter left child for "<<p->data<<":";
            cin>>x;
            if(x != -1)
            {
                t = new Node;
                t->data = x;
                t->lchild = NULL;
                t->rchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }

            cout<<"Enter right child for "<<p->data<<":";
            cin>>x;
            if(x != -1)
            {
                t = new Node;
                t->data = x;
                t->lchild = NULL;
                t->rchild = NULL;
                p->rchild = t;
                q.enqueue(t);
            }
        }
    }

    void Preorder(Node *p) 
    {
        if (p)
        {
            cout << p->data << " ";
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }

    void Preorder()
    {
        Preorder(root);
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

    void inorder()
    {
        inorder(root);
    }

    void postorder(Node *p)
    {
        if(p)
        {
            postorder(p->lchild);
            postorder(p->rchild);
            cout<<p->data<<" ";
        }
    }

    void postorder()
    {
        postorder(root);
    }

    void levelorder(Node *p)
    {
        if(p)
        {
            queue q(10);
            cout<<root->data<<" ";
            q.enqueue(root);
            while(!q.is_empty())
            {   
                p = q.dequeue();
                if(p->lchild)
                {
                    cout<<p->lchild->data<<" ";
                    q.enqueue(p->lchild);
                }
                    
                if(p->rchild)
                {
                    cout<<p->rchild->data<<" ";
                    q.enqueue(p->rchild);
                }
            }
        }
    }

    void levelorder()
    {
        levelorder(root);
    }

    void Iter_lvl_order(Node *p)
    {
        if(p)
        {
            queue q(10);
            cout<<root->data<<" ";
            q.enqueue(root);
            while(!q.is_empty())
            {
                root = q.dequeue();
                if(root->lchild)
                {
                    cout<<root->lchild->data<<" ";
                    q.enqueue(root->lchild);
                }
                if(root->rchild)
                {
                    cout<<root->rchild->data<<" ";
                    q.enqueue(root->rchild);
                }
            }
        }
    }
    
    void Iter_lvl_order()
    {
        Iter_lvl_order(root);
    }

    int count(Node *p)
    {
        int x;
        int y;
        while(p != NULL)
        {
            x = count(p->lchild);
            // cout<<"x= "<<x;
            y = count(p->rchild);
            // cout<<"y= "<<y;
            return x+y+1;
        }
        return 0;
    }

    int count()
    {
        return count(root);
    }
};

int main()
{
    tree t;
    t.create();
    // t.Preorder();
    // cout<<endl;
    // t.inorder();
    // cout<<endl;
    // t.postorder();
    // cout<<endl;
    // t.levelorder();
    // cout<<endl;
    // t.Iter_lvl_order();
    cout<<endl;
    cout<<"Total elements= "<<t.count();   // when doing these the count value is 1 because other pointers are dequeued
}
