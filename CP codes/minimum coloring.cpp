#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1=x1-1;
        y1=y1-1;
        x2=x2-1;
        y2=y2-1;

        int col[2];
        int p1=(x1+y1)%2;
        int p2=(x2+y2)%2;
        if(p1==0 && p2==0)
        {
            col[0]=1;
            col[1]=4;
        }
        if(p1==0 && p2==1)
        {
            col[0]=1;
            col[1]=2;
        }
        if(p1==1 && p2==0)
        {
            col[0]=2;
            col[1]=1;
        }
        if(p1==1 && p2==1)
        {
            col[0]=4;
            col[1]=1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==x1 && j==y1)
                {
                    cout<<1<<' ';
                    continue;
                }
                if(i==x2 && j==y2)
                {
                    cout<<2<<' ';
                    continue;
                }
                cout<<col[(i+j)%2]<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
