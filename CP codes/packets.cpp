#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[6];
    while(true)
    {
        cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
        if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0) break;
        int b=0;
        b+=a[5];
        b+=a[4];
        a[0]-=min(a[0],a[4]*11);
        b+=a[3];
        int s2=a[3]*5;
        if(a[1]>s2) a[1]-=s2;
        else {int r=s2-a[1]; a[1]=0; a[0]-=min(a[0],r*4);}
        b+=a[2]/4;
        int r3=a[2]%4;
        if(r3)
        {
            b++;
            if(r3==1){int u=min(5,a[1]); a[1]-=u; a[0]-=min(a[0],7+(5-u)*4);}
            else if(r3==2){int u=min(3,a[1]); a[1]-=u; a[0]-=min(a[0],6+(3-u)*4);}
            else if(r3==3){int u=min(1,a[1]); a[1]-=u; a[0]-=min(a[0],5+(1-u)*4);}
        }
        b+=a[1]/9;
        int r2=a[1]%9;
        if(r2){b++; a[0]-=min(a[0],36-r2*4);}
        if(a[0]>0) b+=(a[0]+35)/36;
        cout<<b<<"\n";
    }
    return 0;
}
