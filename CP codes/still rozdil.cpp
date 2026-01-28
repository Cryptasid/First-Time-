#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        brr[i]=arr[i];
    }
    sort(brr,brr+n);
    if(brr[0]==brr[1])cout<<"Still Rozdil"<<endl;
    else
    {
    long long min=10000000000;
    int index;
    for(int i=0;i<n;i++)
    {

        if(arr[i]<min)
        {
            min=arr[i];
            index=i;
        }
    }
    cout<<index+1<<endl;
    }


    return 0;
}

