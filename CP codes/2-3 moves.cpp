#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n==1)cout<<2<<endl;
        else cout<<(n+2)/3<<endl;
    }
    return 0;
}
