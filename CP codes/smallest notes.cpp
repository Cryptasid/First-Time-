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
        int notes=0;
        while(N>=0)
        {
            if(N>=100)
            {
                N-=100;
                notes++;
            }

            else if(N>=50)
            {
                N-=50;
                notes++;
            }
            else if(N>=10)
            {
                N-=10;
                notes++;
            }
            else if(N>=5)
            {
                N-=5;
                notes++;
            }
            else if(N>=2)
            {
                N-=2;
                notes++;
            }
            else if(N>=1)
            {
                N-=1;
                notes++;
            }
            else if(N==0)break;

        }
       cout<<notes<<endl;

    }
    return 0;
}
