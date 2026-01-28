#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int i=1;
    int total=m;
    while(i<=total)
    {
        if(i<=n)total-=i;
        if(i==n)i=0;
        i++;

    }
    cout<<total<<endl;
    return 0;
}
