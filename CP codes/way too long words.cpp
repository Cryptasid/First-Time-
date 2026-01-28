#include <iostream>
#include <string>
using namespace std;
int main()
{
    string word;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>word;
        int n=word.size();
        int m=n-2;
        if(n>10)cout<<word[0]<<m<<word[n-1]<<endl;
        else cout<<word<<endl;
    }
    return 0;
}
