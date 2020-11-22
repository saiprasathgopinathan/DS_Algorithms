#include<iostream>
using namespace std;

// SUM OF FIRST N NATURAL NOS starting from 1
// int main()
// {
//     int A[8] = {1, 2, 3, 4, 6, 7, 8};
//     int n = sizeof(A)/sizeof(A[0]);
//     cout<<n<<endl;
//     int sum_natural_nos = n*(n+1)/2;
//     cout<<sum_natural_nos<<endl;
//     int sum = 0;
//     for(int i=0;i<n;i++)
//     {
//         sum += A[i];
//     }
//     int diff = sum_natural_nos - sum;
//     cout<<sum_natural_nos - sum;
//     for(int i=n;i>diff-1;i--)
//     {
//         A[i] = A[i-1];
//     }
//     A[diff-1] = diff;
//     cout<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cout<<A[i]<<" ";
//     }
// }


// SUM OF FIRST N NATURAL NOS starting from middle
// int main()
// {
//     int A[10] = {6, 7, 8, 9, 11, 12, 13, 14, 15};
//     int diff = A[0];
//     int n = sizeof(A)/sizeof(A[0]);
//     int index;
//     int no;
//     int count = 0;
//     for(int i=0; i<n; i++)
//     {
//         if((A[i] - i) != diff)
//         {
//             cout<<diff + i<<endl;
//             no = diff + i;
//             index = i;
//             count++;
//             break;
//         }
//     }
// }


// FINDING MULTIPLE MISSING NOS
// int main()
// {
//     int A[13] = {6,7,8,9, 11,12, 15,16,17,18};
//     int diff = A[0];
//     for(int i=0; i<13;i++)
//     {
//         if(diff != (A[i] -i))
//         {
//             while(diff < A[i] -i)
//             {
//                 cout<<i+diff;
//                 diff++;
//                 cout<<endl;
//             }
//         }
//     }
// }  
// THESE METHODS ARE POSSIBLE ONLY ON SORTED ARRAY


// THE FOLLOWING METHOD IS FOR ARRAY WHICH IS UNSORTED WHICH IS POSSIBLE EVEN FOR SORTED ARRAY
// int main()
// {
//     int A[] = {7,3,1,4,5,9};
//     int h = 9;
//     int n = sizeof(A)/sizeof(A[0]);
//     int H[h];
//     for(int i=0;i<h;i++)
//     {
//         H[i] = 0;
//     }
//     for(int i=0;i<n;i++)
//     {
//         H[A[i]]++;
//     }
//     for(int i=1; i<=h; i++)
//     {
//         if(H[i] == 0)
//         {
//             cout<<i<<endl;
//         }
//     }
// }


// FINDING DUPLICATES AND THEIR COUNTS
// int main()
// {
//     int lastduplicate = 0;
//     int A[] = {3,5,5,6,6,7,8,9,9,9};
//     int n = sizeof(A)/sizeof(A[0]);
//     for(int i=0;i<n;i++)
//     {
//         if(A[i] == A[i+1] && A[i] != lastduplicate)
//         {
//             int j = i+1;
//             while(A[i] == A[j])
//             {
//                 j++;
//             }
//             cout<<A[i]<<" appears "<<j-i<<" times"<<endl;
//             i = j-1;
//         }
//     }
// }


// FINDING DUPLICATES AND THEIR COUNTS USING HASHTABLE
// int main()
// {
//     int A[] = {1,4,4,5,5,7,8,9,9,9,10};
//     int n = sizeof(A)/sizeof(A[0]);
//     int h = A[n-1];
//     int H[h];
//     for(int i=0; i<h; i++)
//     {
//         H[i] = 0;
//     }
//     for(int i=0;i<n;i++)
//     {
//         H[A[i]]++;
//     }
//     for(int i=0;i<h;i++)
//     {
//         if(H[i] > 1)
//         {
//             cout<<i <<" appears "<<H[i]<<" times"<<endl;
//         }
//     }
// }


// K-SUM PAIR USING HASHTABLES. FOR UNSORTED ARRAY
// int main()
// {
//     int A[] = {6,3,8,10,16,7,5,2,9,14};
//     int n = sizeof(A)/sizeof(A[0]);
//     int H[16];
//     int k = 10;
//     for(int i=0;i<16;i++)
//     {
//         H[i] = 0;
//     }
//     for(int i=0;i<n;i++)
//     {
//         H[A[i]]++;
//     }
//     for(int i=0;i<16;i++)
//     {
//         cout<<H[i]<<" ";
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(H[k - A[i]] > 0 && A[i]<k)
//         {
//             cout<<A[i]<<" "<<k - A[i]<<endl;
//         }
//         H[A[i]]++;
//     }
// }


// K-SUM PAIRS
// int main()
// {
//     int A[] = {6,3,8,10,16,7,5,2,9,14};
//     int n = sizeof(A)/sizeof(A[0]);
//     int k = 10;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(A[i] + A[j] == k)
//             {
//                 cout<<A[i]<<" "<<A[j]<<endl;
//             }
//         }
//     }
// }


// FOR SORTED ARRAY FINDING THE SUM
// int main()
// {
//     int A[] = {1,3,4,5,6,8,9,10,12,14};
//     int n = sizeof(A)/sizeof(A[0]);
//     int K[14];
//     int k = 10;
//     for(int i=0, j=n-1; i<j;)
//     {
//         if(A[i] + A[j] == k)
//         {
//             cout<<A[i]<<" "<<A[j]<<endl;
//             i++;
//             j--;
//         }
//         else if(A[i] + A[j] > k)
//         {
//             j--;
//         }
//         else
//         {
//             i++;
//         }
//     }
// }


// FINDING MAX and MIN in single scan
int main()
{
    int A[] = {5,8,3,9,6,2,10,7,-1,4};
    int n = sizeof(A)/sizeof(A[0]);
    int min = 5;
    int max = 5;
    cout<<min<<" "<<max<<endl;
    for(int i=1;i<n;i++)
    {
        if(A[i] < min)
        {
            min = A[i];
        }
        else if(A[i] > max)
        {
            max = A[i];
        }
    }
    cout<<min<<" "<<max<<endl;
}

