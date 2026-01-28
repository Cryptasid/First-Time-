#include<iostream>

using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int domino;
    if(m%2==0)
    {
        domino=(m/2)*n;
    }
    else if(m%2!=0 && m!=1)
    {
        domino=((m-1)/2)*n;
        if(n%2==0)
        {
            domino+=(n/2);
        }
        else domino+=((n-1)/2);
    }
    else if(m==1)
    {
        if(n%2==0)domino=(n/2);
        else if(n==1)domino=0;
        else domino=((n-1)/2);
    }
    cout<<domino<<endl;
    return 0;
}

