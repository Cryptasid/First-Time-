#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int totalsum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        totalsum+=arr[i];
    }
    sort(arr,arr+n,greater<int>());
    int sum=0;
    int count=0;
    for(int i=0;totalsum>=sum;i++)
    {
        sum+=arr[i];
        totalsum-=arr[i];
        count++;
    }
    cout<<count<<endl;
    return 0;
}
