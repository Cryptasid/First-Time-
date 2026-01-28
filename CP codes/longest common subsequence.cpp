#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
int pc(ull x){return __builtin_popcountll(x);}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size(),w=(m+63)/64;
    vector<vector<ull>>b(256,vector<ull>(w,0));
    for(int j=0;j<m;j++)
    {
        unsigned char c=t[j];
        b[c][j>>6]|=1ULL<<(j&63);
    }
    vector<ull> s1(w,0),x(w),y(w),tmp(w);
    for(int i=0;i<n;i++)
    {
       unsigned char c=s[i];

       for(int j=0;j<w;j++)
      {
        x[j]=b[c][j]|s1[j];
       }

    ull carry=1;
    for(int j=0;j<w;j++)
    {
        ull cur=s1[j];
        ull sh=(cur<<1)|carry;
        carry=cur>>63;
        y[j]=sh;
    }
    ull bor=0;
    for(int j=0;j<w;j++)
    {
        ull xv=x[j],yv=y[j];
        ull sub=xv-yv-bor;
        bor=(xv<yv+bor);
        tmp[j]=sub;
    }
    for(int j=0;j<w;j++)
    {
        s1[j]=x[j]&~tmp[j];
    }
    }
    long long ans=0;
    if(m%64==0)
    {
    for(int j=0;j<w;j++)ans+=pc(s1[j]);
    }
    else{
    int last=m&63;
    ull mask=(1ULL<<last)-1;
    for(int j=0;j<w-1;j++)ans+=pc(s1[j]);
    ans+=pc(s1[w-1]&mask);
    }
    cout<<ans<<'\n';
    return 0;
}
//abababab
//bcbb
