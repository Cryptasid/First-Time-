#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    string p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    string e[m];
    for(int i=0;i<n;i++)
    {
        cin>>e[i];
    }
    if(n>m)cout<<"YES"<<endl;
    else if(n<m)cout<<"NO"<<endl;
    else
    {
        int same=0;
        for(int i=0;i<n;i++)
       {
          for(int j=0;j<n;j++)
          {
              if(p[i]==e[j])
              {
                  same++;
                  break;
              }
          }
       }
       if(same%2==1)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
    return 0;
}


