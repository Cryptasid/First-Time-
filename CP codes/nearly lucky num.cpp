#include<iostream>
#include <string>
using namespace std;
int main()
{
    string num;
    cin>>num;
    int f=0;
    int s=0;
    for(int i=0;i<num.size();i++)
    {
        if(num[i]=='4')f++;
        else if(num[i]=='7')s++;
    }
    if(f+s==4 || f+s==7)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
