#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int sorted[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sorted[i]=arr[i];
        }
        sort(sorted,sorted+n);
        int dif=0;
        for(int i=0;i<n;i++)
        {
           if(sorted[i]!=arr[i])
           {
               dif=1;
               break;
           }
        }
        if(dif==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}

