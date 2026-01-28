#include<iostream>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int people=0;
    int high=-1;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        people-=a;
        people+=b;
        if(people>high)high=people;
    }
    cout<<high<<endl;
    return 0;
}
