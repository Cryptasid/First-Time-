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
        int even=0,odd=0;
        for(int i =1;i<=n;i++)
        {
            int a;
            cin>>a;
            if(a%2==0)even++;
            else odd++;

        }
        int k;
        if(even>=odd)k=0;
        else k=1;
        cout<<"2 "<<k<<endl;
    }
    return 0;
}

