#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string,char>digit=
    {
        {"063",'0'},{"010",'1'},{"093",'2'},{"079",'3'},{"106",'4'},{"103",'5'},{"119",'6'},{"011",'7'},{"127",'8'},
        {"107",'9'}
    };
    map<char,string>display=
    {
        {'0',"063"},{'1',"010"},{'2',"093"},{'3',"079"},{'4',"106"},{'5',"103"},{'6',"119"},{'7',"011"},{'8',"127"},
        {'9',"107"}
    };
    string sum;
    while(true)
    {
        cin>>sum;
        if(sum=="BYE")break;
        int x=sum.find('+');
        int y=sum.find('=');
        string A=sum.substr(0,x);
        string B=sum.substr(x+1,y-x-1);
        string NumA="";
        for(int i=0;i<A.size();i+=3)
        {
            string numpartA=A.substr(i,3);
            NumA+=digit[numpartA];
        }
        string NumB="";
        for(int i=0;i<B.size();i+=3)
        {
            string numpartB=B.substr(i,3);
            NumB+=digit[numpartB];
        }
        int a=stoi(NumA);
        int b=stoi(NumB);
        int c=a+b;
        string NumC=to_string(c);
        string C="";
        for(int i=0;i<NumC.size();i++)
        {
            char dig=NumC[i];
            C+=display[dig];
        }
        cout<<A<<"+"<<B<<"="<<C<<endl;
    }
    return 0;
}
