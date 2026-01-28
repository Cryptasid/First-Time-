#include<iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}


int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    int i=0;
    while(n>=0)
    {
        i++;
        if(i%2!=0)
        {
            n=n-gcd(a,n);
        }
        else if(i%2==0)
        {
            n=n-gcd(b,n);
        }
    }
    if(i%2==0)cout<<"0"<<endl;
    else cout<<"1"<<endl;

    return 0;
}

