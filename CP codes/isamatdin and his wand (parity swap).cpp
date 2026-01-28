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
        int arr[n];
        int even=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]%2==0)even++;
        }
        if(even==0 || even ==n)
        {
         for(int i=0;i<n;i++)
         {
             if(i==n-1)cout<<arr[i]<<endl;
             else cout<<arr[i]<<" ";
         }
        }
        else
        {
            sort(arr,arr+n);
            for(int i=0;i<n;i++)
         {
             if(i==n-1)cout<<arr[i]<<endl;
             else cout<<arr[i]<<" ";
         }

        }
    }
    return 0;
}
