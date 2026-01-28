#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    for(int i=0;i<N;i++)
    {
        if(i==N-1)cout<<arr[i];
        else cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

