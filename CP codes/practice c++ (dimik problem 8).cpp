#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int N[3];
        for(int j=0;j<3;j++)
        {
            cin>>N[j];
        }
        int small,mid,big;
        if(N[0]<N[1] && N[0]<N[2])
        {
            small=N[0];
            if(N[1]<N[2])
            {
                mid=N[1];
                big=N[2];
            }
            else
            {
                mid=N[2];
                big=N[1];
            }
        }
        else if(N[0]<N[1])
        {
            mid=N[0];
            small=N[2];
            big=N[1];
        }
        else if(N[0]<N[2])
        {
            mid=N[0];
            small=N[1];
            big=N[2];
        }
        else
        {
            big=N[0];
            if(N[1]<N[2])
            {
                small=N[1];
                mid=N[2];
            }
            else
            {
                small=N[2];
                mid=N[1];
            }
        }
    cout<< "Case "<< i <<": "<< small <<" "<< mid <<" "<< big << endl;
    }
    return 0;
}
