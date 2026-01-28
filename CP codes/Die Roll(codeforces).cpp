#include <iostream>
using namespace std;
int main()
{
    int y,w;
    cin>>y>>w;
    int Max;
    if(y>=w)Max=y;
    else if(w>=y) Max=w;
    int total=6;
    int chance=total-Max+1;
    if(chance==0)cout<<"0/1"<<endl;
    else if(chance==total)cout<<"1/1"<<endl;
    else if(total%chance==0)cout<<(chance/chance)<<"/"<<(total/chance)<<endl;
    else if(total%2==0 && chance%2==0)cout<<(chance/2)<<"/"<<(total/2)<<endl;
    else cout<<chance<<"/"<<total<<endl;
    return 0;
}
