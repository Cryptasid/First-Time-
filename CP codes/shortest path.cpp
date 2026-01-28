#include <bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
int s;
cin>>s;
while(s--)
{
    int n;
    cin>>n;
    string name[10100];
    vector<pair<int,int>>graph[10005];
    int dist[10005];
    bool visited[10005];
    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
    }
    for(int i=1;i<=n;i++)
    {
        cin>>name[i];
        int p;
        cin>>p;
        for(int j=0;j<p;j++)
        {
            int nr,cost;
            cin>>nr>>cost;
            graph[i].push_back({nr,cost});
        }
    }
    int r;
    cin>>r;
    for(int q=0;q<r;q++)
     {
        string city1,city2;
        cin>>city1>>city2;
        int starting=-1,dest=-1;
        for(int i=1;i<=n;i++)
        {
            if(name[i]==city1)starting=i;
            if(name[i]==city2)dest=i;
        }
        for(int i=1;i<=n;i++)
        {
            dist[i]=200001;
            visited[i]=false;
        }
        dist[starting]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,starting});
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            if(visited[u]) continue;
            visited[u]=true;
            for(auto p:graph[u])
            {
                int v=p.first;
                int cost=p.second;
                if(dist[u]+cost<dist[v])
                {
                    dist[v]=dist[u]+cost;
                    pq.push({dist[v],v});
                }
            }
        }
        cout<<dist[dest]<<"\n";
    }
    if(s)cout<<"\n";

}
    return 0;
}
