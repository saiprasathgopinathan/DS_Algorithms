#include <iostream>
#include <fstream>
using namespace std;

class item
{
    public:
    string name;
    int price;
    int quantity;
    
    item(){}
    
    item(string n, int p, int q)
    {
        name = n;
        price = p;
        quantity = q;
    }
    
    friend ofstream & operator<<(ofstream &ofs, item &s);
    friend ifstream & operator>>(ifstream &ifs, item &s);
    friend ostream & operator<<(ostream &os, item &i);
};

ostream & operator<<(ostream &os, item &i)
{
    os<<i.name<<endl;
    os<<i.price<<endl;
    os<<i.quantity<<endl;
    return os;
}

ofstream & operator<<(ofstream &ofs, item &s)
{
    ofs<<s.name<<endl;
    ofs<<s.price<<endl;
    ofs<<s.quantity<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, item &s)
{
    ifs>>s.name;
    ifs>>s.price;
    ifs>>s.quantity;
    return ifs;
}


int main() 
{
    item i;
    string name;
    int price;
    int qnty;
    int n;
    cout<<"Enter the quantity you wanna buy?";
    cin>>n;
    cout<<"Start entering items: "<<endl;
    item *lst[n];
    for(int x=0;x<n;x++)
    {
        cout<<"Enter item name,price, qnty for"<<x+1<<": ";
        cin>>name;
        cin>>price;
        cin>>qnty;
        lst[x] = new item(name, price, qnty);
    }
    
    ofstream outfile("items.txt");
    for(int x=0;x<n;x++)
    {
        outfile<<*lst[x];
    }
    if(outfile)
    {
        cout<<"Sucessfully written in the file"<<endl;
    }
    
    cout<<"Starting reading from the file"<<endl;
    
    // ifstream infile("items.txt");
    // for(int x=0;x<n;x++)
    // {
    //     infile>>i;
    //     cout<<"Item in "<<x<<i<<endl;
    // }

    return 0;
}