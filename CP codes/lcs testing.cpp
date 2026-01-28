#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s,t;
    cin>>s>>t;
    int n=s.size();
    int n2=t.size();
    int mx=0;
    for(int k=0;k<n;k++)
    {
        int index=-1;
        string temp;
        for(int i=k;i<n;i++)
    {

        for(int j=index+1;j<n2;j++)
        {

            if(s[i]==t[j])
            {
                temp+=s[i];
                index=j;
                break;
            }
        }

    }
    int sz=temp.size();
    if(mx<sz)mx=sz;
    }
    cout<<mx<<endl;
    return 0;
}

//abababab
//bcbba
