#include<iostream>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int checker=0;
    for(int i=1; checker<=n; i++)
    {
        checker+=i;
        if(checker==n)
        {
            cout<<"YES"<<endl;
            break;
        }
        else if(checker>n)
        {
            cout<<"NO"<<endl;
            break;
        }
    }
    return 0;
}

