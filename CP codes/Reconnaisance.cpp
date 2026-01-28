#include <iostream>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {

            if(arr[j]>=arr[i] && arr[j]-arr[i]<=d)
            {
                count++;

            }
            else if(arr[j]<arr[i] && arr[i]-arr[j]<=d)
            {
                count++;

            }
        }
    }
    cout<<2*count<<endl;
    return 0;
}

