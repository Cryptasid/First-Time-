#include <bits/stdc++.h>
using namespace std;

long long mod(long long x, long long y, long long n)
{
    long long result=1;
    x=x%n;
    while(y>0)
    {
        if(y%2==1)result = (result * x) % n;
        y=y/2;
        x=(x*x)%n;
    }
    return result;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long x,y,n;
        cin>>x>>y>>n;
        cout<<mod(x,y,n)<<endl;
    }
    return 0;
}
