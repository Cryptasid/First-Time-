#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    while(b!=0)
    {
        long long temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        long long n;
        cin>>n;
        long long upper=n*(n-1);
        long long lower=4;
        long long div=gcd(upper,lower);
        upper/=div;
        lower/=div;
        cout<<"Case "<<i<<": ";
        if(lower==1)
        {
            cout<<upper<<endl;
        }
        else
        {
            cout<<upper<<"/"<<lower<<endl;
        }
    }
    return 0;
}

