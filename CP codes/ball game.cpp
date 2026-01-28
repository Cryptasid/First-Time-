#include<iostream>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int child=1;
    for(int i=1;i<n;i++)
    {

        if(child+i<=n)
        {
            child+=i;
            cout<<child<<" ";
        }
        else {
            child=child+i-n;
            cout<<child<<" ";
        }
        if(i==n-1)cout<<endl;
    }
    return 0;
}
