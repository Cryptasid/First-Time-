#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a==b)cout<<a+a<<endl;
    else
    {
        int mx;
        if(a>b)mx=a;
        else if(b>a)mx=b;
        int coins;
        coins=mx+(mx-1);
        cout<<coins<<endl;
    }


    return 0;
}

