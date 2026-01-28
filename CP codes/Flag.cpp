#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char page[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>page[i][j];
        }
    }
    int check=-1;
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
            if(j+1<m && page[i][j]!=page[i][j+1])
            {
                cout<<"NO"<<endl;
                check=1;
                break;
            }
            if(i+1<n && page[i][j]==page[i+1][j])
            {
                cout<<"NO"<<endl;
                check=1;
                break;
            }
        }
        if(check==1)break;

    }
    if(check!=1)cout<<"YES"<<endl;
    return 0;
}
