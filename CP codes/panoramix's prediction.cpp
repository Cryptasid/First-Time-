#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    int prime=0;
    for(int i=n+1;i<=m;i++)
    {
        int factor=0;
        if(i%2==0)continue;

        for(int j=1;j<=i;j++)
        {
            if(i%j==0)factor++;
        }

        if(factor==2)
        {
            prime=i;
            break;
        }
    }

    if(prime==m)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
