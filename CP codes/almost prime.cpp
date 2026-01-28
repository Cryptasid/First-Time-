#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n<6)
    {
        cout<<0<<endl;
        return 0;
    }
    int count=0;
    for(int i=6;i<=n;i++)
    {
        int x=i;
        vector<int>factors;
        for(int p=2;p*p<=i;p++)
        {
        if(x%p==0)
        {
            factors.push_back(p);
            while(x%p==0)
                x/=p;
        }
        }
        if(x>1)factors.push_back(x);
        if(factors.size()==2)count++;
    }
    cout<<count<<endl;
    return 0;
}
