#include<bits/stdc++.h>
using namespace std;

int main()
{
    string word;
    cin>>word;
    string rev=word;
    reverse(rev.begin(),rev.end());
    int n= word.size();
    if(n%2!=0 && word==rev)cout<<"YES"<<endl;
    else
    {int dif=0;
    for(int i=0;i<word.size();i++)
    {
        if(word[i]!=rev[i])dif++;
        if(dif>2)break;

    }
    if(dif==2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}

