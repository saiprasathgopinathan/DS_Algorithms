#include<iostream>
#include<fstream>
using namespace std;

class item
{
    public:
    string name;
    float price;
    int quanitity;

    item(){}
    item(string n, float p, int q)
    {
        name = n;
        price = p;
        quanitity = q;
    }
    friend ofstream &operator<<(ofstream &fos, item &i);
    friend ifstream &operator>>(ifstream &fis, item &i);
    friend ostream &operator<<(ostream &os, item &i);
};
ofstream &operator<<(ofstream &fos, item &i)
{
    fos<<i.name<<endl;
    fos<<i.price<<endl;
    fos<<i.quanitity<<endl;
    return fos;
}
ostream &operator<<(ostream &os, item &i)
{
    os<<i.name<<endl;
    os<<i.price<<endl;
    os<<i.quanitity<<endl;
    return os;
}
ifstream &operator>>(ifstream &fis, item &i)
{
    fis>>i.name;
    fis>>i.price;
    fis>>i.quanitity;
    return fis;
}

int main()
{
    item i;
    string name;
    int qnty;
    float price;
    int n;
    cout<<"Enter the number of items to purchase: ";
    cin>>n;
    item *lst[n];
    for(int x=0;x<n;x++)
    {
        cout<<endl<<"Enter name, price and quantity of item"<<x+1;
        cin>>name>>price>>qnty;
        lst[x] = new item(name, price, qnty);
    }
    ofstream outfile("item.txt");
    for(int x=0;x<n;x++)
    {
        outfile<<*lst[x];
    }
    if(outfile)
    {
        cout<<endl<<"Written in the file successfully";
    }
    return 0;
}
