#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin>>T;
    cin.ignore();
    for(int i=1;i<=T;i++)
    {
        string N;
        getline(cin,N);
        int cnt=0;
        string Word;
        for(int j=0;j<N.length();j++)
        {

           if(N[j]!=' ') Word+=N[j];
           else {
             if(!Word.empty())
             {
                 cnt++;
                 Word.clear();
             }
           }
        }
        if (!Word.empty()) cnt++;
        cout<<cnt<<"\n";
    }
    return 0;
}
