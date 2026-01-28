#include<iostream>
using namespace std;
int main()
{

    char page[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>page[i][j];
        }
    }
    if(page[0][0]==page[2][2] && page[0][1]==page[2][1] && page[0][2]==page[2][0] && page[1][0]==page[1][2] )
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
