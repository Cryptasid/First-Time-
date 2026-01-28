#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        long long arr[n];
        int odd=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]%2!=0)odd++;
        }
        if(odd>0)
        {
            cout<<2<<endl;
            continue;
        }
        int found=-1;
            for(long long i=3;;i+=2)
            {
                for(int j=0;j<n;j++)
                {

                     if (gcd(arr[j],i)==1)
                    {
                       cout<<i<<endl;
                       found=1;
                       break;
                    }
                }
                if(found==1)break;
            }
            if(found==-1)cout<<-1<<endl;



    }
    return 0;
}

