#include<bits/stdc++.h>
using namespace std;
int main()
{


    int T;
    cin>>T;
    while(T--)
    {
        int d,k;
        cin>>d>>k;
        int unhappy=0;
        for(int i =1;i<=d;i++)
        {
            int a;
            cin>>a;
            if(a>k)unhappy+=(a-k);
        }
        cout<<unhappy<<endl;
    }
return 0;
}
