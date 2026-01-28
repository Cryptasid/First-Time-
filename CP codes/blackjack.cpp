#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int q=10;
    if(n<=10)cout<<"0"<<endl;
    else
    {
        if(n-q==10)cout<<"15"<<endl;
        else if(n-q<=11)cout<<"4"<<endl;
        else cout<<"0"<<endl;

    }

    return 0;
}
