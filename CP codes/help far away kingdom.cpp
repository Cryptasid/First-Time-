#include<iostream>
#include<string>
using namespace std;
int main()
{
    string number;
    cin>>number;
    int integer=0;
    int decimal=0;
    int dotindex=-1;
    for(int i=0;i<number.size();i++)
    {

        if(number[i]!='.' )
        {
            continue;
        }
        else if(number[i]=='.' && (i+1)<number.size())
        {
            decimal=(number[i+1])-'0';
            integer=(number[i-1])-'0';
            dotindex=i;
            break;
        }
    }
    if (dotindex == -1)
    {
        cout<<number<<endl;
        return 0;
    }

    if(integer==9)cout<<"GOTO Vasilisa."<<endl;
    else if(decimal>=5)
    {
        if(dotindex-1>=0)cout<<number.substr(0,dotindex-1)<<integer+1<<endl;

    }
    else cout<<number.substr(0,dotindex)<<endl;


    return 0;
}
