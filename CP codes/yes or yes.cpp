#include<iostream>
#include <string>
#include<cctype>
using namespace std;
int main()
{

    int n;
    cin>>n;
    string str1;
    for (int i=0;i<n;i++)
    {
        cin>>str1;
        for (int j = 0; j < str1.size(); j++)
    {
            str1[j] = tolower(str1[j]);

    }
    if(str1=="yes")cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }

    return 0;
}

