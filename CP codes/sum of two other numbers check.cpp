#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num[3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>num[j];
        }
        if(num[0]+num[1]==num[2] || num[0]+num[2]==num[1] ||num[2]+num[1]==num[0] )cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
