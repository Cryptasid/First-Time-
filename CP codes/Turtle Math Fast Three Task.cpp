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
        vector<int>a(n);
        int sum=0,rem=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            if(a[i]%3==1)rem++;
        }
        if(sum%3==0)cout<<0<<endl;
        else if(sum%3==1)
        {
            if(rem>=1)cout<<1<<endl;
            else cout<<2<<endl;
        }
        else cout<<1<<endl;
    }
    return 0;
}
