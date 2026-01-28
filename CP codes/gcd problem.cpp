#include<iostream>
using namespace std;

int findGCD(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main()
{
    int T;
    cin>>T;
    for(int z=1;z<=T;z++)
    {
        int N;
        cin>>N;
        if(N%2==0)
        {
            cout<<(N/2)-1<<" "<<N/2<<" "<<1<<endl;
            continue;
        }
        int i=3,j=N-i-1;

        while(i+j<=N)
        {

            int gcd=findGCD(i,j);
            if(i+j+gcd==N && i!=gcd && j!=gcd)
            {
                cout<<i<<" "<<j<<" "<<gcd<<endl;
                break;
            }
            if(i+j+gcd<N)j++;
            else
            {
                i++;
                j=N-i-1;
            }
        }
    }

    return 0;
}
