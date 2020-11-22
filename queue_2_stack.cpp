#include<iostream>
#include<stack>
using namespace std;

class queue
{
    private:
    stack<int> e_stk;
    stack<int> d_stk;

    public:
    void enqueue(int x)
    {
        e_stk.push(x);
    }
    int dequeue()
    {
        int x = -1;
        if(d_stk.empty())
        {
            if(e_stk.empty())
            {
                cout<<"Queue is empty";
            }
            else
            {
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
        x = d_stk.top();
        d_stk.pop();
        return x;
    }
};

int main()
{
    int A[] = {1, 3, 5, 7, 9};
 
    queue q;
 
    cout << "Enqueue: ";
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++)
    {
        q.enqueue(A[i]);
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Dequeue: ";
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++)
    {
        cout << q.dequeue() << " ";
    }
}
 
