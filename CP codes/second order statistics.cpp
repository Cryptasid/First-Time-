#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int minimum,loc;
    for(int k=0;k<n-1;k++)
    {
        minimum=arr[k];
        loc=k;
        for(int j=k+1; j<n;j++)
        {
            if(minimum>arr[j])
            {
                minimum=arr[j];
                loc=j;
            }

        }
        int Temp;
        if(minimum!=arr[k])
        {
            Temp=arr[k];
            arr[k]=arr[loc];
            arr[loc]=Temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[0])
        {
            cout<<arr[i]<<endl;
            break;
        }
        else if(i==(n-1) && arr[i]==arr[0])cout<<"NO"<<endl;
    }
    return 0;
}
