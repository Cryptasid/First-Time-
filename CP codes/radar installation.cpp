#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<double,double> &a,const pair<double,double> &b){
    return a.second < b.second;
}

int main(){
    int n, tc = 1;
    double d;
    while(1)
    {
        scanf("%d %lf",&n,&d);
        if(n==0 && d==0)break;

        vector<pair<double,double> > v;
        int ok=1;
        for(int i=0;i<n;i++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            if(y>d)ok=0;
            else
            {
                double t=sqrt(d*d-y*y);
                v.push_back(make_pair(x-t, x+t));
            }
        }

        if(!ok)
        {
            printf("Case %d: -1\n",tc++);
            continue;
        }

        sort(v.begin(),v.end(),cmp);

        int ans=0;
        double last=-1e100;
        for(int i=0;i<(int)v.size();i++)
        {
            if(v[i].first>last)
            {
                ans++;
                last=v[i].second;
            }
        }

        printf("Case %d: %d\n",tc++,ans);
    }
    return 0;
}
