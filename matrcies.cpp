#include<iostream>
using namespace std;

// struct matrix
// {
//     // int a[10];
//     int *a;
//     int n;
// };

// void Disp_diagonal(struct matrix m)
// {
    
//     for(int i=0;i<m.n;i++)
//     {
//         for(int j=0;j<m.n;j++)
//         {
            
//             if(i==j)
//             {
//                 cout<<m.a[i]<<" "; 
//             }
//             else
//             {
//                 cout<<"0 ";
//             }
//         }
//         cout<<endl;
//     }
// }

// DIAGONAL MATRIX USING STRUCT
// "void Set(struct matrix *m, int i, int j, int x)
// {
//     if(i==j)
//     {
//         m->a[i-1] = x;
//     }
// }

// int Get(struct matrix m, int i, int j)
// {
//     if(i == j)
//     {
//         return m.a[i-1];
//     }
//     else
//     {
//         return 0;
//     }
// }
// "

// int main()
// {
    // struct matrix m;
    // m.n = 4;
    // Set(&m, 1, 1, 1); Set(&m, 2, 2, 2); Set(&m, 3, 3, 3); Set(&m, 4, 4, 4);
    // Disp(m);
    // cout<<endl<<Get(m,1,4)<<endl;
    // return 0;
// }


// LOWER TRIANGULAR MATRIX
// int main()
// {
//     for(int i=0;i<4;i++)
//     {
//         for(int j=0;j<4;j++)
//         {
//             if(i>=j)
//                 cout<<i+1<<" ";
//             else
//                 cout<<"0 ";
//         }
//         cout<<endl;
//     }
// }

// class lower
// {
//     int *a;
//     int n;
//     public:
//     lower(int n1)
//     {
//         n = n1;
//         a = new int[n*(n+1)/2];
//     }
//     void Set(int i, int j, int x)
//     {
//         if(i<=j)
//         {
//             a[j*(j-1)/2+i-1] = x;
//         }
//     }

//     int get(int i, int j)
//     {
//         if(i<=j)
//         {
//             return a[j*(j-1)/2+i-1];
//         }
//         else
//             return 0;
//     }

//     void disp_lower()
//     {
//         // cout<<"About to Display"<<m.n;
//         for(int i=1; i<=n; i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(i<=j)             // Change condition for lower triangular matrix and I and J positions
//                 {
//                     cout<<a[j*(j-1)/2+i-1]<<" ";
//                 }
//                 else
//                 {
//                     cout<<"0 ";
//                 }
//             }
//             cout<<endl;
//         }
//     }
// };


// int main()
// {
//     int x, n;
//     cout<<"Enter dimension: ";
//     cin>>n;
//     lower m(n);
//     cout<<"Enter values"<<endl;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cin>>x;
//             m.Set(i, j, x);
//         }
//     }
//     cout<<endl<<endl<<"******************************************"<<endl;
//     m.disp_lower();
// }

// class Upper
// {
//     int *a;
//     int n;
//     public:
//     Upper(int n1)
//     {
//         n = n1;
//         a = new int(n*(n+1/2));
//     }
//     void Set(int i, int j, int x)
//     {
//         if(i<=j)
//         {
//             a[j*(j-1)/2 + i-1] = x;
//         }
//     }
//     void Disp()
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n; j++)
//             {
//                 if(i<=j)
//                 {
//                     cout<<a[j*(j-1)/2 + i-1]<<" ";
//                 }
//                 else
//                 {
//                     cout<<"0 ";
//                 }
//             }
//             cout<<endl;
//         }
//     }

// };

// int main()
// {
//     Upper u(4);
//     int x;
//     cout<<"Enter values; "<<endl;
//     for(int i=1;i<=4;i++)
//     {
//         for(int j=1;j<=4;j++)
//         {
//             cin>>x;
//             u.Set(i, j, x);
//         }
//     }

//     u.Disp();
// }


// SPARSE MATIRIX
// class Element   // Element's row col and value
// {
//     public:
//     int i;
//     int j;
//     int x;
// };

// class Sparse   // Matrices row col and number
// {
//     int m;
//     int n;
//     int num;
//     Element *ele;
//     public:
//     Sparse(int m1, int n1, int num1)
//     {
//         m = m1;
//         n = n1;
//         num = num1;
//         ele = new Element[n];
//     }
//     Sparse operator+(Sparse &s);
//     friend istream &operator>>(istream &is, Sparse &s);
//     friend ostream &operator<<(ostream &os, Sparse &s);
// };
// Sparse Sparse :: operator+(Sparse &s)
// {
//     int i, j ,k;
//     if(m != s.m && n != s.n)
//     {
//         return Sparse(0, 0, 0);
//     }
//     Sparse *s3 = new Sparse(m,n,num+s.num);
//     i=j=k=0;
//     while(i < num && j < s.num)
//     {
//         if(ele[i].i < s.ele[j].i)
//         {
//             s3->ele[k++] = ele[i++];
//         }
//         else if(ele[i].i > s.ele[j].i)
//         {
//             s3->ele[k++] = s.ele[j++];
//         }
//         else
//         {
//             if(ele[j].j < s.ele[j].j)
//             {
//                 s3->ele[k++] = ele[i++];
//             }
//             else if(ele[j].j > s.ele[j].j)
//             {
//                 s3->ele[k++] = s.ele[j++];
//             }
//             else
//             {
//                 s3->ele[k] = ele[i];
//                 s3->ele[k++].x = ele[i++].x + s.ele[j++].x;
//             }
//         }
//     }
//     for(;i<num;i++)s3->ele[k++] = ele[i++];
//     for(;j<s.num;j++)s3->ele[k++] = s.ele[j++];
//     s3->num = k;

//     return *s3;
// }


// istream & operator>>(istream &is, Sparse &s)
// {
//     cout<<"Enter non zero elements"<<endl;
//     for(int i=0;i<s.num;i++)
//     {
//         cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
//     }
//     return is;
// }
// ostream & operator<<(ostream &os, Sparse &s)
// {
//     int k = 0;
//     for(int i=0;i<s.m;i++)
//     {
//         for(int j=0;j<s.n;j++)
//         {
//             if(i == s.ele[k].i && j == s.ele[k].j)
//             {
//                 cout<<s.ele[k++].x<<" ";
//             }
//             else
//             {
//                 cout<<"0 ";
//             }
//         }
//         cout<<endl;
//     }
//     return os;
// }

// int main()
// {
//     Sparse s1(5, 5, 5);
//     cin>>s1;
//     cout<<"First Matrix"<<endl;
//     cout<<s1;

//     Sparse s2(5, 5, 5);
//     cin>>s2;
//     cout<<"Second Matrix"<<endl;
//     cout<<s2;

//     Sparse s3 = s1 + s2;
//     cout<<"Sum matrix"<<endl;
//     cout<<s3;
// }


// POLYNOMIAL REPRESENTATION
class term
{
    public:
    int exp;
    int coef;
};

class poly
{
    int n;
    term *t;
    public:
    poly(int n1)
    {
        n = n1;
        t = new term[n];
    }
    poly operator+(poly &p);
    friend istream &operator>>(istream &is, poly &p);
    friend ostream &operator<<(ostream &os, poly &p);
};

poly poly::operator+(poly &p)
{
    int i=0, j=0, k=0;
    poly *p3 = new poly(n + p.n);
    while(i<p.n && j < p.n)
    {
        if(t[i].exp > p.t[j].exp)
        {
            p3->t[k++] = t[i++];
        }
        else if(t[i].exp < p.t[j].exp)
        {
            p3->t[k++] = p.t[j++];
        }
        else
        {
            p3->t[k].exp = t[i].exp;
            p3->t[k++].coef = t[i++].coef + p.t[j++].coef;
        }
    }
    for(;i<n;i++)p3->t[k++] = t[i++];
    for(;j<p.n;j++)p3->t[k++] = p.t[j++];
    p3->n = k;
    return *p3;
}

istream &operator>>(istream &is, poly &p)
{
    cout<<"Enter Coefficients and Exponents"<<endl;
    for(int i=0;i<p.n;i++)
    {
        cin>>p.t[i].coef>>p.t[i].exp;
    }
    return is;
}

ostream &operator<<(ostream &os, poly &p)
{
    cout<<"C E"<<endl;
    for(int i=0;i<p.n;i++)
    {
        cout<<p.t[i].coef<<" "<<p.t[i].exp<<endl;
    }
}

int main()
{
    poly p1(3);
    cin>>p1;
    cout<<"Polynomial 1"<<endl;
    cout<<endl<<p1;
    cout<<"Polynomial 2"<<endl;
    poly p2(3);
    cin>>p2;
    cout<<endl<<p2;
    cout<<endl;
    poly p3 = p1 + p2;
    cout<<"Sum of polynomials"<<endl;
    cout<<p3;

}
