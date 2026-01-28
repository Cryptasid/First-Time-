#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector< vector<ll> > ct;
vector< vector< vector<ll> > > up;
vector<ll> C,S;
vector<int> dice,lastdice;
int r,m;
bool found;

void dfs(int i,int st)
{
    if(found)return;
    if(i==r)
    {
        for(int j=0;j<m;j++)
        {
            if(S[j]!=C[j])return;
        }
        lastdice=dice;
        found=1;
        return;
    }
    int rem=r-i;
    for(int v=st;v<=50;v++)
    {
        bool limit=0;
        for(int j=0;j<m;j++)
        {
            S[j]+=ct[v][j];
            if(S[j]>C[j])limit=1;
        }
        if(!limit)
        {
            int left=rem-1;
            bool stopper=0;
            for(int j=0;j<m;j++){
                ll fut=(left>0)?up[j][v][left]:0;
                if(S[j]+fut<C[j]){stopper=1;break;}
            }
            if(!stopper)
            {
                dice[i]=v;
                dfs(i+1,v);
                if(found)return;
            }
        }
        for(int j=0;j<m;j++)S[j]-=ct[v][j];
        if(found)return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        vector< vector<int> > d(n);
        for(int i=0;i<n;i++)
        {
            int f;cin>>f;
            d[i].resize(f);
            for(int j=0;j<f;j++)cin>>d[i][j];
        }
        cin>>r>>m;
        vector<int> V(m);
        C.assign(m,0);
        int mxV=0;
        for(int i=0;i<m;i++)
        {
            cin>>V[i]>>C[i];
            mxV=max(mxV,V[i]);
        }
        int MX=mxV;
        vector<ll> w(MX+1,0);
        w[0]=1;
        for(int i=0;i<d.size();i++)
        {
            vector<int> &x=d[i];
            vector<ll> nw(MX+1,0);
            for(int s=0;s<=MX;s++)
            {
                if(w[s]==0)continue;
                for(int j=0;j<x.size();j++)
                {
                    int f=x[j];
                    int t=s+f;
                    if(t<=MX)nw[t]+=w[s];
                }
            }
            w.swap(nw);
        }
        ct.assign(51, vector<ll>(m));
        for(int f=1;f<=50;f++)
        {
            for(int i=0;i<m;i++)
            {
                int idx=V[i]-f;
                ct[f][i]=(idx>=0&&idx<=MX)?w[idx]:0;
            }
        }
        up=vector< vector< vector<ll> > >(m, vector< vector<ll> >(52, vector<ll>(r+1,0)));
        for(int i=0;i<m;i++)
        {
            for(int s=50;s>=1;s--)
            {
                ll mx=ct[s][i];
                if(s<50)mx=max(mx,up[i][s+1][1]);
                up[i][s][1]=mx;
                for(int k=1;k<=r;k++)up[i][s][k]=mx*k;
            }
        }
        dice.assign(r,0);
        S.assign(m,0);
        lastdice.clear();
        found=0;
        dfs(0,1);
        if(!found)cout<<"Impossible\n";
        else
        {
            cout<<"Final die face values are";
            for(int i=0;i<lastdice.size();i++)cout<<" "<<lastdice[i];
            cout<<"\n";
        }
    }
    return 0;
}

