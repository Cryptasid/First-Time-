#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    int n;
    cin>>n;
    char s[n+1],t[n+1];
    cin>>s>>t;
    sort(s,s+n);
    sort(t,t+n);
    int i;
    for( i=0;i<n;i++)
    {
        if(s[i]!=t[i])break;
    }
    if(i==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    }
    return 0;
}
