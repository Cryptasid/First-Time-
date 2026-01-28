#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int T;
    cin>> T;

    for(int i=1; i<=T ; i++)
    {
        long long N;
        cin>> N;
        long long root= sqrt(N);

        if(root*root==N)cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}





