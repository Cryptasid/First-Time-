#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        string num="";
        if(N%2!=0)
        {
            for(int i=0;i<N;i++)
         {
            if(i%2==0)num.push_back('0');
            else num.push_back('1');
         }
        }
        else
        {
            for(int i=0;i<N;i++)
         {
            if(i==0 || i==N-1)num.push_back('1');
            else num.push_back('0');
         }
        }
        cout<<num<<endl;
    }
    return 0;
}
