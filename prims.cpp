#include<iostream>
# define I 32767
using namespace std;

int cost [8][8] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I}};

int near[8] = {I, I, I, I, I, I, I, I};    // tracks which vertex is visitied and not
int t[2][7];     // the output matrix which stores the starting and ending vertex

int main()
{
    int u, v, k, min = I, n = 7;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(min > cost[i][j])
            {
                u = i;
                v = j;
                min = cost[i][j];
            }
        }
    }
    near[u] = near[v] = 0;
    t[0][0] = u;
    t[1][0] = v;

    //finding which between the two vertices has next vertex at low cost with the remaining non zero vertices
    for(int i=1; i<=n;i++)
    {
        if(near[i] != 0)
        {
            if(cost[i][u] < cost[i][v])
            {
                near[i] = u;
            }
            else
            {
                near[i] = v;
            }
        }
    }

    for(int i=1;i<n-1;i++)
    {
        min = I;
        for(int j=1;j<=n;j++)
        {
            if(min > cost[j][near[j]] && near[j] != 0)
            {
                k = j;
                min = cost[j][near[j]];
            }
        }

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for(int j=1;j<=n;j++)
        {
            if(cost[j][near[j]] > cost[j][k]  & near[j] != 0)
            {
                near[j] = k;
            }
        }
    }

    for(int i=0;i<n-1;i++)
    {
        cout<<t[0][i]<<" "<<t[1][i]<<endl;
    }

}