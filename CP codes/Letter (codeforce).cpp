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
    int minrow,mincolumn,maxrow,maxcolumn,found=-1;
    for(int i=0;i<n && found==-1;i++)
    {

        for(int j=0;j<m;j++)
        {
            if(page[i][j]=='.')continue;
            else if(page[i][j]=='*')
            {
                minrow=i;
                mincolumn=j;
                maxcolumn=j;
                found=1;
                break;
            }
        }

    }
    for(int i=0;i<n ;i++)
    {

        for(int j=0;j<m;j++)
        {
            if(page[i][j]=='.')continue;
            else if(page[i][j]=='*')
            {
                maxrow=i;
                if(j<mincolumn)mincolumn=j;
                if(j>maxcolumn)maxcolumn=j;

            }
        }

    }
    for(int i=minrow;i<=maxrow;i++)
    {
        for(int j=mincolumn;j<=maxcolumn;j++)
        {
            cout<<page[i][j];
        }
        cout<<endl;
    }

    return 0;
}
