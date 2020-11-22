#include<iostream>
// #include<cstring>
using namespace std;


// CHANGING CASES
// int main()
// {
//     aing a = "Welcome";
//     int n = sizeof(a)/sizeof(a[0]);
//     for(int i=0;i<n;i++)
//     {
//         if(a[i] >= 65 && a[i] <= 90)
//             a[i] = a[i]+32;
//         else if(a[i] >= 97 && a[i] <= 122)
//             a[i] = a[i]-32;
//     }
//     cout<<a;
// }


// COUNTING VOWELS, WORDS, CONSONANTS
// int main()
// {
//     aing a="how are you dude";
//     int n = sizeof(a)/sizeof(a[0]);
//     cout<<n<<endl;
//     int word_count = 0, v_count = 0, c_count = 0;
//     for(int i=0; a[i]!='\0'; i++)
//     {
//         if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
//         {
//             v_count++;
//         }
//         else if(a[i] != 'a' || a[i] != 'e' || a[i] != 'i' || a[i] != 'o' || a[i] != 'u')
//         {
//             c_count++;
//         }
//     }

//     cout<<"Vowel_count= "<<v_count<<endl;
//     cout<<"Consonant_count= "<<c_count<<endl;
// }


// STRING VALIDATION
// int validate(string a)
// {
//     for(int i=0; a[i] != '\0';i++)
//     {
//         if(!(a[i] >= 65 && a[i] <=90) && !(a[i] >= 97 && a[i] <= 122) && !(a[i] >= 48 && a[i] <= 57))
//         {
//             cout<<a[i]<<" ";
//             return 0;
//         }
//     }
//     return 1;
// }
// int main()
// {
//     string a = "Ani?321";
//     int x = validate(a);
//     if(x==1)
//     {
//         cout<<"valid";
//     }
//     else
//     {
//         cout<<"Not valid";
//     }
// }

// STRING REVERSE
// int main()
// {
//     char a[] = "Ice";
//     cout<<"Before swap= "<<a<<endl;
//     int n = sizeof(a)/sizeof(a[0]);
//     for(int i=0, j=n-2; i<=j; i++, j--)
//     {
//         int temp = a[i];
//         a[i] = a[j];
//         a[j] = temp;
//     }
//     cout<<"after swap"<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cout<<a[i];
//     }
//     cout<<endl;
// }


// PALINDROME
// int main()
// {
//     string a = "mada";
//     int n = 0;
//     for(int i=0; a[i]!='\0'; i++)
//     {
//         n+=1;
//     }
//     cout<<n<<endl;
//     for(int i=0, j=n; i<=j; i++,j--)
//     {
//         if(a[i] == a[j])
//         {
//             cout<<a[i]<<" "<<a[j]<<endl;
//             cout<<"Palindrome"<<endl;
//         }
//         else
//         {
//             cout<<a[i]<<" "<<a[j]<<endl;
//             cout<<"Not a palindrome"<<endl;
//         }
//     }
// }


// FINDING DUPLICATE STRING IN THE LIST
// int main()
// {
//     string a = "off";
//     int H[26];
//     for(int i=0;i<26;i++)
//     {
//         H[i] = 0;
//     }
//     for(int i=0;i<7;i++)
//     {
//         H[a[i]-97]++;
//     }
//     for(int i=0;i<26;i++)
//     {
//         cout<<H[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=0;i<26;i++)
//     {
//         if(H[i]>1)
//         {
//             cout<<char(i+97)<<" "<<H[i]<<endl;
//         }
//     }
// }


// FINDING DUPLICATES USING BITWISE
// int main()
// {
//     char a[] = "finding";
//     long int h=0, x=0;
//     for(int i=0; a[i]!='\0'; i++)
//     {
//         x = 1;
//         x = x<<a[i] - 97;
//         if(x & h > 0)
//         {
//             cout<<i<<" entered";
//             cout<<a[i]<<" is a duplicate"<<endl;
//         }
//         else
//         {
//             cout<<i<<" else entered"<<endl;
//             h = x|h;
//             cout<<h<<endl;
//         }
//     }
// }


// ANAGRAM
// int main()
// {
//     char a[]="medical";
//     char b[]="decimal";
//     int n = sizeof(a)/sizeof(a[0]);
//     int H[26];
//     int sum = 0;
//     for(int i=0;i<26;i++)
//     {
//         H[i] = 0;
//     }
//     for(int i=0;a[i]!='\0';i++)
//     {
//         H[a[i]-97]++;
//     }
//     for(int i=0;b[i]=='\0';i++)
//     {
//         H[a[i]-97] -=1;
//         cout<<H[a[i]-97]<<endl;
//         if(H[a[i] -97] < 0)
//         {
//             cout<<H[a[i]]<<endl;
//             cout<<"It's not anagram"<<endl;
//             break;
//         }
//         cout<<"Final loop done<<endl";
//         if(b[i] == '\0')
//         {
//             cout<<"Entered"<<endl;
//             cout<<"anagram"<<endl;
//         }
//     }
// }

//     for(int i=0;b[i]!='\0';i++)
//     {
//         H[b[i]-97]++;
//     }
//     for(int i=0;i<26;i++)
//     {
//         if(H[i] >1)
//         {
//             sum+=H[i];
//         }
//     }
//     // cout<<sum;
//     if(sum == 2*(n-1))
//     {
//         cout<<"anagram"<<endl;
//     }
//     else
//     {
//         cout<<"not anagram"<<endl;
//     }
// }


// PERMUTATION
// void swap(char *i, char *j)
// {
//     char t;
//     t = *i;
//     *i = *j;
//     *j = t;
// }
// void permute(string c, int l, int r)
// {
//     if(l==r)
//     {
//         cout<<c<<endl;
//     }
//     else
//     {
//         for(int i=l;i<=r;i++)
//         {
//             swap(&c[l], &c[i]);
//             permute(c, l+1, r);
//             swap(&c[l], &c[i]);
//         }
//     }
// }
// int main()
// {
//     string c = "ABC";
//     int n = c.size();
//     permute(c, 0, n-1);
// }


// PERMUTATION
void permute(string s, int k)
{
    static int a[10];
    static char R[10];
    if(s[k] == '\0')
    {
        R[k] = '\0';
        cout<<R<<endl;
    }
    else
    {
       for(int i=0; s[i] != '\0'; i++)
       {
           if(a[i] == 0)
           {
                R[k] = s[i];
                a[i] = 1;
                permute(s, k+1);
                a[i] = 0;
           }
       } 
    }
}
int main()
{
    string s = "ABCD";
    permute(s, 0);
}