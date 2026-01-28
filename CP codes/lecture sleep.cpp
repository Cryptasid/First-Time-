#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int thr[n];
    for(int i=0;i<n;i++)
    {
        cin>>thr[i];
    }
    int up[n];
    for(int i=0;i<n;i++)
    {
        cin>>up[i];
    }
    int awake=0;
    for(int i=0;i<n;i++)
    {
        if(up[i]==1)
        {
            awake+=thr[i];
        }
    }
    int wakeup=0;
    for(int i=0;i<k;i++)
    {
        if(up[i]==0)
        {
            wakeup+=thr[i];
        }
    }
    int max_wakeup=wakeup;
    for(int i=k;i<n;i++)
    {
        if(up[i]==0)
        {
            wakeup+=thr[i];
        }
        if(up[i-k]==0)
        {
            wakeup-=thr[i-k];
        }
        if(wakeup>max_wakeup)max_wakeup=wakeup;
    }
    cout<<awake+max_wakeup<<endl;
    return 0;
}


