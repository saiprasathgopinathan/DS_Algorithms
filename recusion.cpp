#include<iostream>
using namespace std;

int sum(int n)   // sum of n natural numbers
{
    if(n==0)
    {
        return 0;
    }
    return sum(n-1)+n;
}

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return fact(n-1)*n;
}

int pow(int m, int n)   // m = number n = times  It performs in O(n)
{
    if(n==0)    
    {
        return 1;
    }
    return pow(m, n-1)*m;          // because this statement executes for n times
}

int pow_reduce(int m ,int n)    // this executes in O(n/2)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        if(n%2==0)
        {
            return pow(m*m,n/2);          // because when number is even it gets squared each time, thus "n" can be halved
        }
        else
        {
            return m*pow(m*m,(n-1)/2);
        }
    }
}

int ncr(int n, int r)   // this method uses pascal triangle
{
    if(r==n || r==0)
    {
        return 1;
    }
    return ncr(n-1, r) + ncr(n-1, r-1);
}

int taylor(int x, int n)
{
    double r=1;
    static double p = 1, f = 1;
    if(n==0)
    {
        return 1;
    }
    r = taylor(x, n-1);
    p = p*x;
    f = f*n;
    return r+(p/f);
}

int fib_excess_recur(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fib_excess_recur(n-1)+fib_excess_recur(n-2);
}

int f[10];
int fib_memoization(int n)
{
    if(n<=1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if(f[n-1]==-1)
        {
            f[n-1] = fib_memoization(n-1);
        }
        if(f[n-2]==-1)
        {
            f[n-2] = fib_memoization(n-2);
        }
        return f[n-1] + f[n-2];
    }
}

void TOH(int n, int a, int b, int c) // n = number of disks, a, b, c = tower names
{
    if(n>0)
    {
        TOH(n-1, a, c ,b);
        cout<<"("<<a<<", "<<c<<")"<<endl;
        TOH(n-1, b, a ,c);
    }
}

int main()
{
    TOH(4, 1, 2, 3);
    // cout<<fib_excess_recur(6);
    // for(int i=0;i<10;i++)
    // {
    //     f[i] = -1;
    // }
    // cout<<fib_memoization(6);
    return 0;
}