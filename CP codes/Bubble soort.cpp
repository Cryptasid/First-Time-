#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int swap=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=i+1;j--)
        {
            if(a[j]<a[j-1])
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                swap++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
        if(i!=n-1) cout<<' ';
    }
    cout<<endl;
    cout<<swap<<endl;
    return 0;
}

