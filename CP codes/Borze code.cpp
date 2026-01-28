#include <iostream>
#include <string>
using namespace std;
int main()
{
    string Borze;
    cin>>Borze;
    int n= Borze.size();
    for(int i=0;i<n;i++)
    {
        if(Borze[i]=='.' )
        {

            if(Borze[i-1]!='-')cout<<"0";
            else if(Borze[i-1]=='-' && Borze[i-2]=='-')cout<<"0";
        }
        else if(Borze[i]=='-')
        {
            if(Borze[i+1]=='.')
            {
                cout<<"1";
                i++;
            }

            else if(Borze[i+1]=='-' )
            {
                cout<<"2";
                i++;
            }
        }



    }
    cout<<endl;
    return 0;
}
