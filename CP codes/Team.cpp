#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int ques=0;
    while(T--)
    {

        int count=0;
        for(int i=0;i<3;i++)
        {
            int n;
            cin>>n;
            if(n==1)count++;

        }
        if(count>=2)ques++;
    }
    cout<<ques<<endl;
    return 0;
}
