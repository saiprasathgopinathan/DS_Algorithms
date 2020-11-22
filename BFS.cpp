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
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    if(front == NULL)
    {
        cout<<"Queue is empty";
    }    
    else
    {
        Node *t = front;
        x = front->data;
        front = front->next;
        delete t;
    }
    return x;
}

int isempty()
{
    return front == NULL;
}

void BFS(int G[][7], int start, int n)
{
    int visitied[7] = {0};
    int i = start;
    cout<<i<<" ";
    visitied[i] = 1;
    enqueue(i);
    while(!isempty())
    {
        i = dequeue();
        for(int j=1;j<n;j++)
        {
            if(visitied[j] == 0 && G[i][j] == 1)
            {
                cout<<j<<" ";
                visitied[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    if(visited[start] == 0)
    {
        visited[start] = 1;
        cout<<start<<" ";
        for(int j=1;j<n;j++)
        {
            if(visited[j] == 0 && G[start][j] == 1)
            {
                DFS(G, j, n);
            }
        }
    }
}


int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    // BFS(G, 1, 7);
    cout<<endl;
    DFS(G, 1, 7);
}
