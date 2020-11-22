#include<iostream>
using namespace std;

// THIS IS A TWO POINTER QUEUE
class queue
{
    public:
    int size;
    int front;
    int rear;
    int *Q;
};

void create(queue *q, int s)
{
    q->size = s;
    q->front = -1;
    q->rear = -1;
    q->Q = new int[q->size];
}

void enqueue(queue *q, int x)
{
    if(q->rear == q->size-1)
    {
        cout<<"Queue is full";
    }
    else
    {
        q->rear += 1;
        q->Q[q->rear] = x;
    }
}

void dequeue(queue *q)
{
    int x = -1;
    if(q->rear == q->front)
    {
        cout<<"Queue is empty";
    }
    else
    {
        q->front += 1;
        x = q->Q[q->front];
    }
}

void disp(queue *q)
{
    for(int i=q->front+1; i<=q->rear;i++)
    {
        cout<<q->Q[i]<<" ";
    }
    cout<<endl;
}

void enqueue_circular(queue *q, int x)
{
    if((q->rear+1)%q->size == q->front)
    {
        cout<<"Queue is full";
    }
    else
    {
        q->rear = q->rear+1%q->size;
        q->Q[q->rear] = x;
    }
}

void dequeue_circular(queue *q)
{
    int x;
    if((q->front+1)%q->size == q->rear)
    {
        cout<<"Queue is empty";
    }
    else
    {
        q->front = q->front+1%q->size;
        x = q->Q[q->front];
    }
}


int main()
{
    queue q;
    create(&q, 7);
    enqueue_circular(&q, 10);
    enqueue_circular(&q, 20);
    enqueue_circular(&q, 30);
    enqueue_circular(&q, 40);
    enqueue_circular(&q, 50);
    enqueue_circular(&q, 60);
    enqueue_circular(&q, 70);

    disp(&q);
    dequeue_circular(&q);
    dequeue_circular(&q);
    dequeue_circular(&q);
    enqueue_circular(&q, 10);
    enqueue_circular(&q, 20);
    disp(&q);

    // enqueue(&q, 10);
    // enqueue(&q, 20);
    // enqueue(&q, 30);
    // enqueue(&q, 40);
    // enqueue(&q, 50);
    // enqueue(&q, 60);
    // enqueue(&q, 70);

    // disp(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // enqueue(&q, 10);
    // enqueue(&q, 20);

    // disp(&q);

}