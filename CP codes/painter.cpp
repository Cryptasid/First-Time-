#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long double ld;
const ld eps = 1e-12L;

ld maxg(vector<int>& a)
{
    int n=a.size();
    vector<vector<int>> t;
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                vector<int> v(3);
                v[0]=i; v[1]=j; v[2]=k;
                t.push_back(v);
            }
        }
    }
    int m=t.size();
    if(m==0) return 0.0L;
    int rows=n;
    int cols=m+n+1;
    vector<vector<ld>> tab(rows+1,vector<ld>(cols,0.0L));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vector<int> p=t[j];
            if(p[0]==i||p[1]==i||p[2]==i) tab[i][j]=1.0L;
        }
        tab[i][m+i]=1.0L;
        tab[i][cols-1]=(ld)a[i];
    }
    for(int j=0;j<m;j++)tab[rows][j]=-1.0L;
    tab[rows][cols-1]=0.0L;
    vector<int> b(rows);
    for(int i=0;i<rows;i++)b[i]=m+i;
    while(true)
    {
        int en=-1;
        ld mn=-eps;
        for(int j=0;j<cols-1;j++)
        {
            if(tab[rows][j]<mn)
            {
                mn=tab[rows][j];
                en=j;
            }
        }
        if(en==-1) break;
        int lv=-1;
        ld br=0.0L;
        for(int i=0;i<rows;i++)
        {
            ld v=tab[i][en];
            if(v>eps)
            {
                ld r=tab[i][cols-1]/v;
                if(lv==-1||r<br-1e-14L||(fabsl(r-br)<=1e-14L && b[i]>b[lv]))
                {
                    lv=i;
                   br=r;
                }
            }
        }
        if(lv==-1) return 1e18;
        ld piv=tab[lv][en];
        for(int j=0;j<cols;j++) tab[lv][j]/=piv;
        for(int i=0;i<=rows;i++)
        {
            if(i==lv)continue;
            ld f=tab[i][en];
            if(fabs(f)<=0)continue;
            for(int j=0;j<cols;j++)tab[i][j]-=f*tab[lv][j];
        }
        b[lv]=en;
    }
    vector<ld> x(m,0.0L);
    for(int i=0;i<rows;i++)
    {
        int j=b[i];
        if(j<m) x[j]=tab[i][cols-1];
    }
    ld ans=0.0L;
    for(int i=0;i<m;i++) ans+=x[i];
    return ans;
}
int mink(vector<int>& r,int G)
{
    int n=r.size();
    int mx=0;
    long long s=0;
    for(int i=0;i<n;i++)
        {
             if(r[i]>mx)mx=r[i];
             s+=r[i];
        }
    int k0=max((mx+49)/50,(int)ceil((s+3LL*G)/(50.0L*n)));
    for(int k=k0;k<=2000;k++)
    {
        vector<int> c(n);
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            c[i]=k*50-r[i];
            if(c[i]<0)
            {
                ok=false;
                break;
            }
        }
        if(!ok) continue;
        ld mg=maxg(c);
        if(mg+1e-9L>=(ld)G) return k;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        int n;
        cin>>n;
        if(n==0) break;
        vector<int> r(n);
        for(int i=0;i<n;i++) cin>>r[i];
        int g;
        cin>>g;
        int a=mink(r,g);
        if(a<0) a=0;
        cout<<a<<"\n";
    }
    return 0;
}

